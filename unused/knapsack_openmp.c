#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

#define MAX_ITER 100
#define EPSILON 0.0001
#define INITIAL_ALPHA 0.0001
#define MAX_THREADS 4

int nthreads;
int tid;

int main(int argc, char *argv[]) {

    unsigned long n, w; /* n denotes the number of items and w denotes the space limit */

    n = atoll(argv[1]);
    w = n/10;

    double *v_list; /* the values of items */
    double *w_list; /* the weights of items */

    v_list = (double*)malloc(n*sizeof(double));
    w_list = (double*)malloc(n*sizeof(double));

    unsigned int seed = atoi(argv[2]);

    srand(seed);
    for (unsigned long i=0; i<n; i++){
        v_list[i] = (double)(rand() % 100 + 1)/100;
        w_list[i] = (double)(rand() % 100 + 1)/100;
    }

    double cpu1 = ((double) clock())/CLOCKS_PER_SEC;
    
    /* initialize lambda as 0 */
    double lambda = 0;
    double last_w = 0;
    double alpha = INITIAL_ALPHA;

    for (unsigned long t=1; t<=MAX_ITER; t++){
        
        double current_w = 0;
        double local_w[MAX_THREADS] = {0.0};
        
        #pragma omp parallel private(tid)
        {
            nthreads = omp_get_num_threads();
            tid = omp_get_thread_num();
            for (unsigned long i=tid; i < n; i+=nthreads){
                if (v_list[i] - lambda*w_list[i] > 0){
                    local_w[tid] += w_list[i];
                }
            }
        }
        
        for(tid = 0; tid < nthreads; tid++){
            current_w += local_w[tid];
        }

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

    /* obtain final results */

    double final_w = 0;
    double final_v = 0;

    for (unsigned long i=0; i<n; i++){
        if ((v_list[i] - lambda*w_list[i] > 0)&&(final_w + w_list[i] <= w)){
            final_w += w_list[i];
            final_v += v_list[i];
        }
    }

    double cpu2 = ((double) clock())/CLOCKS_PER_SEC;
    
    double cpu = cpu2 - cpu1;

    printf("The number of threads: %d\n", nthreads);
    printf("The number of items: %lu\n", n);
    printf("The space limit: %lu\n", w);
    printf("Final space used: %lf\n", final_w);
    printf("Total values obtained: %lf\n", final_v);
    printf("Execution time (s): %lf\n\n", cpu);

}
