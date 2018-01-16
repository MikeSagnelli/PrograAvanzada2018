#include <stdio.h>

int main() {
    int a = 4;
    int j;
    int *p;
    float f = 7.5;
    int max = 2147483647;
    long d;
    int b = a + (int)f; //11
    float c = a*f;
    int arreglo[5] = {0, 2};
    d = (long)max * (long)max;
    p = arreglo;

    for(int k = 0; k < 5; k++){
        *p = 67;
        p++;
    }

    printf(" a = %p, a = %d, j = %d, b = %d, d= %ld \n", p, a, j, b, d);
    printf(" f = %f, c = %f, arreglo[1] = %d \n", f, c, arreglo[1]);

    return 0;
}