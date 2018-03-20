#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X;// initial batman position on x axis
    int Y;// initial batman position on y axis
    scanf("%d%d", &X, &Y);
    
    int X1 = 0; // search box x initial coordinate
    int Y1 = 0; // search box y initial coordinate
    int X2 = W - 1; // search box x last coordinate
    int Y2 = H - 1; // search box y last coordinate
    
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);
        
        if (bombDir[0] == 'U'){
            Y2 = Y - 1;
        }
        else if (bombDir[0] == 'D'){
            Y1 = Y + 1;
        }
        
        if (bombDir[0] == 'L' || bombDir[1] == 'L'){
            X2 = X - 1;
        }
        else if (bombDir[0] == 'R' || bombDir[1] == 'R'){
            X1 = X + 1;
        }
        
        X = X1 + (X2 - X1) / 2;
        Y = Y1 + (Y2 - Y1) / 2;
        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // the location of the next window Batman should jump to.
        printf("%d %d\n", X, Y);
    }

    return 0;
}