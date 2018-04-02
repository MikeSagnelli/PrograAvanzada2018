// Author: Michelle Sagnelli D'urzo
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void initMatrix(Matrix *myMatrix, int nRows, int nColumns){
    myMatrix->rows = nRows;
    myMatrix->columns = nColumns;
    myMatrix->data = calloc(nRows, sizeof(char *));
    for(int i = 0; i < nRows; i++){
        myMatrix->data[i] = calloc(nRows, sizeof(char));
    }
}

void printMatrix(Matrix *myMatrix){
    for(int i = 0; i < myMatrix->rows; i++){
        for(int j = 0; j < myMatrix->columns; j++){
            printf("%c ", myMatrix->data[i][j]);
        }
        printf("\n");
    }
}


int checkArrowsToChange(Matrix *myMatrix){
    int nArrowsToChange = 0;
    int nArrowsAhead = 0;
    for(int i = 0; i < myMatrix->rows; i++){
        for(int j = 0; j < myMatrix->columns; j++){
            if(myMatrix->data[i][j] != '.'){
                if(myMatrix->data[i][j] == '^'){
                    if(i != 0){
                        for(int k = 0; k < i; k++){
                            if(myMatrix->data[k][j] == '^' ||
                               myMatrix->data[k][j] == 'v' ||
                               myMatrix->data[k][j] == '<' ||
                               myMatrix->data[k][j] == '>'){
                                nArrowsAhead++;
                                break;
                            }
                        }
                    }
                }
                else if(myMatrix->data[i][j] == '>'){
                    if(j != myMatrix->columns - 1){
                        for(int k = j + 1; k < myMatrix->columns; k++){
                            if(myMatrix->data[i][k] == '^' ||
                               myMatrix->data[i][k] == 'v' ||
                               myMatrix->data[i][k] == '<' ||
                               myMatrix->data[i][k] == '>'){
                                nArrowsAhead++;
                                break;
                            }
                        }
                    }
                }
                else if(myMatrix->data[i][j] == 'v'){
                    if(i != myMatrix->rows - 1){
                        for(int k = i + 1; k < myMatrix->rows; k++){
                            if(myMatrix->data[k][j] == '^' ||
                               myMatrix->data[k][j] == 'v' ||
                               myMatrix->data[k][j] == '<' ||
                               myMatrix->data[k][j] == '>'){
                                nArrowsAhead++;
                                break;
                            }
                        }
                    }
                }
                else if(myMatrix->data[i][j] == '<'){
                    if(j != 0){
                        for(int k = 0; k < j; k++){
                            if(myMatrix->data[i][k] == '^' ||
                               myMatrix->data[i][k] == 'v' ||
                               myMatrix->data[i][k] == '<' ||
                               myMatrix->data[i][k] == '>'){
                                nArrowsAhead++;
                                break;
                            }
                        }
                    }
                }

                if(nArrowsAhead == 0){
                    nArrowsToChange++;
                    int nArrowsInLine = 0;
                    for(int k = 0; k < myMatrix->rows; k++){
                        if(k == i){
                            continue;
                        }
                        else{
                            if(myMatrix->data[k][j] == '^' ||
                            myMatrix->data[k][j] == 'v' ||
                            myMatrix->data[k][j] == '<' ||
                            myMatrix->data[k][j] == '>'){
                                nArrowsInLine++;
                                break;
                            }
                        }
                    }
                    if(nArrowsInLine == 0){
                        for(int k = 0; k < myMatrix->columns; k++){
                            if(k == j){
                                continue;
                            }
                            else{
                                if(myMatrix->data[i][k] == '^' ||
                                myMatrix->data[i][k] == 'v' ||
                                myMatrix->data[i][k] == '<' ||
                                myMatrix->data[i][k] == '>'){
                                    nArrowsInLine++;
                                    break;
                                }
                            }
                        }
                    }
                    if(nArrowsInLine == 0){
                        return -1;
                    }
                }
                else{
                    nArrowsAhead = 0;
                }
            }
        }
    }
    return nArrowsToChange;
}