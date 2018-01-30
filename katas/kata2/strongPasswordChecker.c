#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_STRING_LENGTH 6
#define MAX_STRING_LENGTH 20

int strongPasswordChecker(char* s);

int main(){
    printf("%d operations needed for making password strong\n", strongPasswordChecker("hola"));
    printf("%d operations needed for making password strong\n", strongPasswordChecker("alejandro"));
    printf("%d operations needed for making password strong\n", strongPasswordChecker("aaaaaaa"));
    return 0;
}

int strongPasswordChecker(char* s){
    int size = strlen(s);
    int n_operations = 0;
    
    if(size < 6){
        //printf("The string doesn't have an optimal number of characters.\n");
        n_operations = 6 - size;
        //printf("insert %d characters more.", n_operations);
    }
    if(size > 20){
        //printf("The string doesn't have an optimal number of characters.\n");
        n_operations = size - 20;
        //printf("delete %d characters", n_operations);
    }

    int n_min = 0,
        n_may = 0,
        n_dig = 0,
        n_special = 0,
        n_adj_equal_char = 0;

    char temp_char = s[0];
    
    for(int i = 0; i < size; i++){
        if(s[i] != temp_char && n_adj_equal_char != 0){
            temp_char = s[i];
        }
        else if(s[i] == temp_char && i != 0){
            n_adj_equal_char++;
            if(n_adj_equal_char == 3){
                //printf("Password should not contain 3 adjacent equal characters.\n");
                n_operations++;
                n_adj_equal_char = 0;
            }
        }
        if(s[i] > 47 && s[i] < 58){
            n_dig++;
        }
        else if(s[i] > 64 && s[i] < 91){
            n_may++;
        }
        else if(s[i] > 96 && s[i] < 123){
            n_min++;
        }
        else{
            n_special++;
        }
    }
    if(n_operations == 0){
        if(n_min == 0){
        //printf("Password is not strong enough, missing lower cases.\n");
        n_operations++;
        }
        if(n_may == 0){
            //printf("Password is not strong enough, missing upper cases.\n");
            n_operations++;
        }
        if(n_dig == 0){
            //printf("Password is not strong enough, missing digits\n");
            n_operations++;
        }
    }
    
    if(n_operations == 0){
        printf("The password is strong!\n");
    }

    return n_operations;
}