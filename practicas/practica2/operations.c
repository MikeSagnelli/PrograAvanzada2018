#include <assert.h>
#include "operations.h"
#define MAX_INT 2147483646

/**
 * Use long addition to catch overflow
 */

int add(int a, int b){
    // Do the addition and check if there is an overflow
    long c = (long) a + b;

    assert(c < MAX_INT && c > -MAX_INT);
    return (int)c;
}

/**
 * Use long substraction to catch overflow
 */

int substraction(int a, int b){
    // Do the substraction and check if there is an overflow
    long c = (long) a - b;

    assert(c < MAX_INT && c > -MAX_INT);
    return (int)c;
}