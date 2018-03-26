#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.1416

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
double degreeToRadians(double x);
 
int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;
        scanf("%d%d", &opponentX, &opponentY);
        
        int hasBoost = 1;
        double angleInRad = degreeToRadians(nextCheckpointAngle);        
        int thrust;
        
        if(nextCheckpointAngle < 90 || nextCheckpointAngle > -90){
            double requiredForce = nextCheckpointDist * cos(angleInRad) * 0.15;
            if(requiredForce > 100){
                thrust = 100;
            } else if (requiredForce < 0){
                thrust = 0;
            }
            else{
                thrust = floor(requiredForce);
            }
        }
        else{
            thrust = 0;   
        }
        
        if(nextCheckpointDist > 3000 && hasBoost == 1 && nextCheckpointAngle == 0){
            printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            hasBoost = 0;
        }
        else{
            printf("%d %d %d\n", nextCheckpointX, nextCheckpointY, thrust);
        }
    }

    return 0;
}

double degreeToRadians(double x){
    return ((x * PI) / 180.0);   
}