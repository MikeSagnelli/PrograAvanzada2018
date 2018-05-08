#include <stdio.h>
#include <stdlib.h>

int max(int sum, int subs, int mult);
int min(int sum, int subs, int mult);

int main(){
    // Storing input
    int testCases;
    scanf("%d", &testCases);

    int nNumbers[testCases];
    int** numbers;
    numbers = calloc(testCases, sizeof(int *));
    for(int i = 0; i < testCases; i++){
        scanf("%d", &nNumbers[i]);
        numbers[i] = calloc(nNumbers[i], sizeof(int));
        for(int j = 0; j < nNumbers[i]; j++){
            scanf("%d", &numbers[i][j]);
        }
    }

    // Printing gathered input to verify
    // for(int i = 0; i < testCases; i++){
    //     for(int j = 0; j < nNumbers[i]; j++){
    //         printf("%d ", numbers[i][j]);
    //     }
    //     printf("\n");
    // }

    // Solution
    int x, y, z, num;
    for(int i = 0; i < testCases; i++){
        x = y = numbers[i][0];
        for(int j = 1; j < nNumbers[i]; j++){
            num = numbers[i][j];
            if(num >= 0){
                x = max(x + num, x - num, x * num);
                y = min(y + num, y - num, y * num);
            }
            else{
                z = max(x + num, x - num, y * num);
                y = min(y + num, y - num, x * num);
                x = z;
            }
        }
        printf("%d\n", y);
    }

    return 0;
}

int max(int sum, int subs, int mult){
    if(sum >= subs && sum >= mult){
        return sum;
    } 
    if(subs >= sum && subs >= mult){
        return subs;
    }
    return mult;
}

int min(int sum, int subs, int mult){
    if(sum <= subs && sum <= mult){
        return sum;
    } 
    if(subs <= sum && subs <= mult){
        return subs;
    }
    return mult;
}