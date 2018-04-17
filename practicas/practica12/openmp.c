#include <stdio.h>
#include <omp.h>

//export OMP_NUM_THREADS=400
int main(){

    int tid;
    int gid;
    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        gid = tid;
        printf("Hello World! %d %d\n", tid, gid);
    }
    return 0;
}