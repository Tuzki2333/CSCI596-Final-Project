#include <stdio.h>
#include <stdlib.h>

#define MAX_ITER 100
#define EPSILON 0.0001
#define LEARNING_RATE 0.01

int main(int argc, char *argv[]) {

    FILE *fp;
    unsigned long n, w;

    fp = fopen("inputs/knapsackInstance-n-10-W-1.txt", "r");
    fscanf(fp, "%lu", &n);
    fscanf(fp, "%lu", &w);

    printf("%lu %lu\n", n, w);

    double *v_list;
    double *w_list;

    v_list = (double*)malloc(n*sizeof(double));
    w_list = (double*)malloc(n*sizeof(double));

    for (int i=0; i<n; i++){
        fscanf(fp, "%lf", &v_list[i]);
        fscanf(fp, "%lf", &w_list[i]);
    }

    for (int i=0; i<n; i++){
        printf("%lf %lf\n", v_list[i], w_list[i]);
    }

    fclose(fp);

    double lambda = 0;

    for (int t=1; t<=MAX_ITER; t++){
        double current_w = 0;
        double current_v = 0;
        for (int i=0; i<n; i++){
            if (v_list[i] - lambda*w_list[i] > 0){
                current_w += w_list[i];
                current_v += v_list[i];
            }
        }
        printf("%d %lf %lf %lf \n", t, lambda, current_w, current_v);
        if ((current_w <= (1+EPSILON)*w)&&(current_w >= (1-EPSILON)*w)){
            break;
        }
        lambda += LEARNING_RATE * (current_w - w);
        if (lambda < 0){
            lambda = 0;
        }
    }
}