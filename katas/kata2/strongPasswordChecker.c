#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN_STRING_LENGTH 6
#define MAX_STRING_LENGTH 20

int strongPasswordChecker(char* s);

int main(){
    strongPasswordChecker("hola");
    strongPasswordChecker("Hola123");
    strongPasswordChecker("aaaaaaa");
    return 0;
}

int strongPasswordChecker(char* s){
    int size = strlen(s);

    if(size < 6 || size > 20){
        printf("The string has an optimal number of characters.\n");
        return 1;
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
            if(n_adj_equal_char >= 3){
                printf("Password should not contain 3 adjacent equal characters.\n");
                return 1;
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
    
    if(n_min > 0 && n_may > 0 && n_dig > 0){
        printf("The password is strong!\n");
    }
    else if(n_min == 0){
        printf("Password is not strong enough, missing lower cases.\n");
        return 1;
    }
    else if(n_may == 0){
        printf("Password is not strong enough, missing upper cases.\n");
        return 1;
    }
    else if(n_dig == 0){
        printf("Password is not strong enough, missing digits cases.\n");
        return 1;
    }
    return 0;
}