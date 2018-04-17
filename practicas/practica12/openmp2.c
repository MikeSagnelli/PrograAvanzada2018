#include <stdio.h>
#include <omp.h>

#define SIZE 200000

//export OMP_NUM_THREADS=400
int main(){

    int a[SIZE];
    int b[SIZE];
    int c[SIZE];
    int chunk = 100;
    int j;

    for(int i = 0; i < SIZE; i++){
        a[i] = i;
        a[i] = 2 * i;
    }

    #pragma omp parallel shared(a,b,c,chunk) private(j)
    {
        #pragma omp for schedule(dynamic, chunk) nowait
        for(j = 0; j < SIZE; j++){
            c[j] = a[j] + b[j];
        }
    }
    return 0;
}