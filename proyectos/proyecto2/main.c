// Author: Michelle Sagnelli D'urzo
#include <stdio.h>
#include "matrix.h"

int main(){
    // Gather the input logic
    int numberOfTests;
    scanf("%d", &numberOfTests);
    Matrix matrices[numberOfTests];
    
    for(int i = 0; i < numberOfTests; i++){
        int rows, columns;
        scanf("%d %d", &rows, &columns);
        initMatrix(&matrices[i], rows, columns);
        for(int j = 0; j < rows; j++){
            scanf("%s", &matrices[i].data[j][0]);
        }
    }
    // Proccessing the information
    int arrowsToChange;
    for(int i = 1; i <= numberOfTests; i++){
        printf("Case #%d: ", i);
        arrowsToChange = checkArrowsToChange(&matrices[i-1]);
        if(arrowsToChange == -1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n", arrowsToChange);
        }
    }

    return 0;
}