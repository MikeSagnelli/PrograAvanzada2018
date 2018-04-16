#include <stdio.h>
#include "hash.h"

typedef enum{false, true} bool;

bool hashApproach(HashInt *hash, int flightLength, int nMovies, int *movies, int *firstMovie, int *secondMovie);

int main(){

    // Gather input
    printf("How much time will the flight take? (in minutes)\n");
    int flightLength;
    scanf("%d", &flightLength);

    printf("How many movies are there in the list?\n");
    int nMovies;
    scanf("%d", &nMovies);
    int movies[nMovies];

    printf("Please write their lengths:\n");
    HashInt hash;
    hashInit(&hash, nMovies);
    for(int i = 0; i < nMovies; i++){
        scanf("%d", &movies[i]);
        hashInsert(&hash, movies[i], false);
    }

    // Process input calling hashApproach function
    int firstMovie, secondMovie;
    bool result = hashApproach(&hash, flightLength, nMovies, movies, &firstMovie, &secondMovie);

    // Print result
    if(result == true){
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}

bool hashApproach(HashInt *hash, int flightLength, int nMovies, int *movies, int *firstMovie, int *secondMovie){
    for(int i = 0; i < nMovies; i++){
        *firstMovie = movies[i];

        hashInsert(hash, *firstMovie, true);

        *secondMovie = flightLength - *firstMovie;

        int *result = hashGet(hash, *secondMovie);

        if(result != NULL && *result == false){
            return true;
        }
    }

    return false;
}