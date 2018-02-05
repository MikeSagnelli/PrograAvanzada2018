#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define LEFT_CHAR 'l'
#define RIGHT_CHAR 'r'
#define UP_CHAR 'u'
#define DOWN_CHAR 'd'
#define TRUE "true"
#define FALSE "false"
#define ASK_MESSAGE "Please write your sequence string: "
#define ERROR_MESSAGE "ERROR: Please make sure all characters are valid directions."

int judge(char *moveSequence);

int main(){
    char sequence[MAX_STRING_LENGTH];
    int result;
    
    printf("%s", ASK_MESSAGE);
    scanf("%s", sequence);
    
    result = judge(sequence);

    if(result == 0){
        printf("%s", FALSE);
    }
    else if(result == 1){
        printf("%s", TRUE);
    }
    else if (result == -1){
        printf("%s", ERROR_MESSAGE);
        return 1;
    }

    return 0;
}

int judge(char *moveSequence){
    int nLeft = 0,
        nRight = 0,
        nUp = 0,
        nDown = 0;
    char temp;

    for(int i = 0; i < strlen(moveSequence); i++){
        temp = tolower(moveSequence[i]);
        switch(temp){
            case LEFT_CHAR:
                nLeft++;
                break;
            case RIGHT_CHAR:
                nRight++;
                break;
            case UP_CHAR:
                nUp++;
                break;
            case DOWN_CHAR:
                nDown++;
                break;
            default:
                return -1;
        }
    }
    return (nLeft == nRight && nUp == nDown);
}