#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    /*
    for (unsigned long i=0; i<n; i++){
        printf("%lf %lf\n", v_list[i], w_list[i]);
    }
    */

    double cpu1 = ((double) clock())/CLOCKS_PER_SEC;

    /* obtain final results */

    double final_w = 0;
    double final_v = 0;

    for (unsigned long i=0; i<n; i++){
        
        if (final_w + w_list[i] <= w){
            final_w += w_list[i];
            final_v += v_list[i];
        }
    }

    double cpu2 = ((double) clock())/CLOCKS_PER_SEC;

    double cpu = cpu2 - cpu1;

    printf("The number of items: %lu\n", n);
    printf("The space limit: %lu\n", w);
    printf("Final space used: %lf\n", final_w);
    printf("Total values obtained: %lf\n", final_v);
    printf("Execution time (s): %lf\n\n", cpu);

}
