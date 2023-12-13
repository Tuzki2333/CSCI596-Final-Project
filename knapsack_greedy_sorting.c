#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct my_str
{
    double value;
    unsigned long index;
};

void swap(struct my_str *a, struct my_str *b) {
  struct my_str t = *a;
  *a = *b;
  *b = t;
}

long long partition(struct my_str *array, long long low, long long high) {

  double pivot = array[high].value;
  long long i = (low - 1);

  for (long long j = low; j < high; j++) {
    if (array[j].value < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(struct my_str *array, long long low, long long high) {

  long long *stack = (long long*)malloc((high-low+1)*sizeof(long long));
  long long top = -1;
  stack[++top] = low;
  stack[++top] = high;

  while (top >= 0) {
      high = stack[top--];
      low = stack[top--];
      long long pivot = partition(array, low, high);
      if (pivot - 1 > low) {
          stack[++top] = low;
          stack[++top] = pivot - 1;
      }
      if (pivot + 1 < high) {
          stack[++top] = pivot + 1;
          stack[++top] = high;
      }
  }
}

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

    struct my_str *ratio_list =  (struct my_str *)malloc(n*sizeof(struct my_str));

    for (unsigned long i=0; i<n; i++){
        ratio_list[i].value = - v_list[i]/w_list[i];
        ratio_list[i].index = i;
    }

    /*
    for (unsigned long i=0; i<n; i++){
        printf("%lf\n", ratio_list[i].value);
    }
    */

    quickSort(ratio_list, 0, n - 1);

    /*
    for (unsigned long i=0; i<n; i++){
        printf("%lf\n", ratio_list[i].value);
    }
    */

    /* obtain final results */

    double final_w = 0;
    double final_v = 0;

    for (unsigned long i=0; i<n; i++){
        
        if (final_w + w_list[ratio_list[i].index] <= w){
            final_w += w_list[ratio_list[i].index];
            final_v += v_list[ratio_list[i].index];
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