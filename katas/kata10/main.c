// Author: Michelle Sagnelli D'urzo
#include <stdio.h>

#define true 1
#define false 0

// Byte range
// 0 - 127 = 0000 0000 - 0111 1111
// 128 - 191 = 1000 0000 - 1011 1111
// 192 - 223 = 1100 0000 - 1101 1111
// 224 - 239 = 1110 0000 - 1110 1111
// 240 - 255 = 1111 1111 - 1111 1111
int main(){
    // Handling input
    int n;
    printf("Please write the number of integers in the array:\n");
    scanf("%d", &n);
    int integers[n];
    printf("Please write the %d numbers:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &integers[i]);
    }
    
    // Processing input
    int count = 0;
    int isUTF = true;
    for(int i = 0; i < n; i++){
        if(integers[i] < 0 || integers[i] > 255){
            isUTF = false;
            break;
        }
        if(count == 0){
            if(integers[i] >= 192 && integers[i] <= 223){
                count = 1;
            }
            else if(integers[i] >= 224 && integers[i] <= 239){
                count = 2;
            }
            else if(integers[i] >= 240 && integers[i] <= 255){
                count = 3;
            }
            else if(integers[i] >= 128 && integers[i] <= 191){
                isUTF = false;
                break;
            }
        }
        else{
            if(integers[i] >= 128 && integers[i] <= 191){
                count--;
            }
            else{
                isUTF = false;
                break;
            }
        }
    }
    if(count > 0){
        isUTF = false;
    }

    // Printing output
    if(isUTF == true){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    return 0;
}