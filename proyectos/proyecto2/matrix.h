// Author: Michelle Sagnelli D'urzo
typedef struct m{
    int rows;
    int columns;
    char** data;
} Matrix;

void initMatrix(Matrix *, int, int);
void printMatrix(Matrix *);
int checkArrowsToChange(Matrix *myMatrix);