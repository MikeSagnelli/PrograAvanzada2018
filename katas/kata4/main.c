#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define TRUE 1
#define FALSE 0
#define TRUE_STR "true"
#define FALSE_STR "false"

int not_a_number();

int main(){
    printf("Please write your string to validate: ");

    char str[MAX_STRING_LENGTH];    
    scanf ("%[^\n]%*c", str);
    
    // value to return
    int boolean = TRUE;

    // iterators and counters
    int iterator = 0;
    int number_of_dots = 0;
    int number_of_e = 0;
    int number_of_percentage = 0;
    int number_of_numbers = 0;

    // save indexes
    int dot_indexes[2];
    int e_index[1];
    int comma_indexes[(strlen(str) / 3) + 4];
    
    while(boolean == TRUE){
        if(iterator == strlen(str)){
            break;
        }

        char temp = str[iterator];

        // Check conditions
        if(number_of_dots > 1 && number_of_e == 0){
            boolean = not_a_number();
            break;
        }
        
        if(number_of_e == 1 && number_of_dots > 2){
            boolean = not_a_number();
            break;
        }
        else if(number_of_dots == 2){
            if(dot_indexes[0] > e_index[0]){
                boolean = not_a_number();
                break;
            }
            else if(dot_indexes[1] < e_index[0]){
                boolean = not_a_number();
                break;
            }
        }
        
        if(number_of_e > 1){
            boolean = not_a_number();
            break;
        }

        if(number_of_percentage > 1){
            boolean = not_a_number();
            break;
        }
        else if(number_of_percentage == 1 && str[strlen(str) - 1] != 37){
            boolean = not_a_number();
            break;
        }

        // Analysing character
        if(temp == 101){
            e_index[0] = iterator;
            number_of_e++;
        }        
        else if(temp == 44){
            // If a comma is not followed by 3 numbers
            if((strlen(str) - iterator) < 3){
                boolean = not_a_number();
                break;
            }
            else{
                if(str[iterator + 1] < 48 || str[iterator + 1] > 57){
                    boolean = not_a_number();
                    break;
                }
                else if(str[iterator + 2] < 48 || str[iterator + 2] > 57){
                    boolean = not_a_number();
                    break;
                }
                else if(str[iterator + 3] < 48 || str[iterator + 3] > 57){
                    boolean = not_a_number();
                    break;
                }
            }
            
            // If a comma doesn't follow another comma and 3 numbers
            if(iterator > 3){
                if(str[iterator - 1] < 48 || str[iterator - 1] > 57){
                    boolean = not_a_number();
                    break;
                }
                else if(str[iterator - 2] < 48 || str[iterator - 2] > 57){
                    boolean = not_a_number();
                    break;
                }
                else if(str[iterator - 3] < 48 || str[iterator - 3] > 57){
                    boolean = not_a_number();
                    break;
                }
                else if(str[iterator - 4] != 44){
                    boolean = not_a_number();
                    break;
                }
            }
            

        }
        else if(temp == 46){
            dot_indexes[number_of_dots] = iterator;
            number_of_dots++;
        }
        else if(temp == 37){
            number_of_percentage++;
        }
        else if(temp >= 48 && temp <= 57){
            number_of_numbers++;
        }
        else{
            boolean = not_a_number();
            break;
        }

        iterator++;
    }

    if(boolean == TRUE){
        printf("%s\n", TRUE_STR);
    }

    return 0;
}

int not_a_number(){
    printf("%s\n", FALSE_STR);
    return FALSE;
}