#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);
int testAddition(void);
int testSubstraction(void);

int main(){
    printTestMessage(testAddition(),
                     "add test passed! ", 
                     "add test failed! ");    
    printTestMessage(testSubstraction(),
                     "substraction test passed! ", 
                     "substraction test failed! ");
    return 0;
}

void printTestMessage(int condition, 
                      char *messagePassed, 
                      char *messageFailed){
    if (condition){
        printf("%s\n", messagePassed);
    }
    else{
        printf("%s\n", messageFailed);
    }
}

int testAddition(void){
    // Test add
    int a = 4,
        b = 3,
        result = add(a,b),
        expected = a + b;

    return result == expected;
}

int testSubstraction(void){
    // Test substraction
    int a = 5,
        b = 2,
        result = substraction(a, b),
        expected = a - b;
    
    return result == expected;
}