#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

#define MAX_ITER 100
#define EPSILON 0.0001
#define INITIAL_ALPHA 0.0001

int nprocs;  /* Number of processes */
int myid;    /* My rank */

int main(int argc, char *argv[]) {

    unsigned long n, w; /* n denotes the number of items and w denotes the space limit */
    
    unsigned long k; /* k is the number of classes */

    k = atoll(argv[1]);
    n = atoll(argv[2]);
    w = k/10;

    double** v_list; /* the values of items */
    double** w_list; /* the weights of items */

    /* generate dynamic array */
    v_list = (double**)malloc(k*sizeof(double*));
    w_list = (double**)malloc(k*sizeof(double*));
    
    for (unsigned long i=0; i<k; i++){
        v_list[i] = (double*)malloc(n*sizeof(double));
        w_list[i] = (double*)malloc(n*sizeof(double));
    }

    /* randomly generate values and weights */
    
    unsigned int seed = atoi(argv[3]);

    srand(seed);
    for (unsigned long i=0; i<k; i++){
        for (unsigned long j=0; j<n; j++){
            v_list[i][j] = (double)(rand() % 100 + 1)/100;
            w_list[i][j] = (double)(rand() % 100 + 1)/100;
        }
    }

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    double cpu1 =  ((double) clock())/CLOCKS_PER_SEC;
    
    /* initialize lambda as 0 */
    double lambda = 0;
    double last_w = 0;
    double alpha = INITIAL_ALPHA;

    for (unsigned long t=1; t<=MAX_ITER; t++){
        
        MPI_Bcast(&lambda, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        double current_w = 0;
        double local_w = 0;
        for (unsigned long i=myid; i<k; i+=nprocs){
            double temp;
            unsigned long temp_j;
            for (unsigned long j=0; j<n; j++){
                if (j == 0){
                    temp = v_list[i][j] - lambda*w_list[i][j];
                    temp_j = 0;
                }
                else{
                    if (v_list[i][j] - lambda*w_list[i][j] > temp){
                        temp = v_list[i][j] - lambda*w_list[i][j];
                        temp_j = j;
                    }
                }
            }
            if (temp > 0){
                local_w += w_list[i][temp_j];
            }
        }

        MPI_Reduce(&local_w, &current_w, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (myid == 0){
            if (abs(current_w-w) <= EPSILON*w){
                break;
            }
            
            lambda += alpha * (current_w - w);
            if (lambda < 0){
                lambda = 0;
            }

            if ((t>1)&&(abs(last_w-w)<abs(current_w-w))){
                alpha *= 0.5;
            }
            last_w = current_w;
        }

    }

    if (myid == 0){

        /* obtain final results */

        double final_w = 0;
        double final_v = 0;

        for (unsigned long i=0; i<k; i++){
            double temp;
            unsigned long temp_j;
            for (unsigned long j=0; j<n; j++){
                if (j == 0){
                    temp = v_list[i][j] - lambda*w_list[i][j];
                    temp_j = 0;
                }
                else{
                    if (v_list[i][j] - lambda*w_list[i][j] > temp){
                        temp = v_list[i][j] - lambda*w_list[i][j];
                        temp_j = j;
                    }
                }
            }
            if ((temp > 0)&&(final_w + w_list[i][temp_j] <= w)){
                final_w += w_list[i][temp_j];
                final_v += v_list[i][temp_j];
            }
        }

        double cpu2 = ((double) clock())/CLOCKS_PER_SEC;
        double cpu = cpu2 - cpu1;

        printf("The number of processes: %d\n", nprocs);
        printf("The number of classes: %lu\n", k);
        printf("The number of items in each class: %lu\n", n);
        printf("The space limit: %lu\n", w);
        printf("Final space used: %lf\n", final_w);
        printf("Total values obtained: %lf\n", final_v);
        printf("Execution time (s): %lf\n\n", cpu);
    }

    MPI_Finalize();

}
