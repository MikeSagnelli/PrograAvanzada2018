// Author: Michelle Sagnelli D'urzo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1100
#define MAX_WORD_LENGTH 10

char * reverse(char * string);

int main(){
    // Input reading section
    int nLines;
    scanf("%d%*c", &nLines);
    
    char **line = (char **) malloc(sizeof(char *) * nLines);
    for (int i = 0; i < nLines; i++) {
        line[i] = (char *) malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%[^\n]%*c", line[i]);
    }

    // Processing section
    for (int i = 0; i < nLines; i++) {
        printf("%s\n", reverse(line[i]));
    }
    
    return 0;
}

char * reverse(char * string) {
    int nWords = 1;
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] == ' ') {
            nWords++;
        }
    }
    char **words = (char **)malloc(sizeof(char *) * nWords);
    for (int i = 0; i < nWords; i++) {
        words[i] = (char *) malloc(sizeof(char) * MAX_WORD_LENGTH);
    }
    int currentWord = 0;
    int currentWordIndex = 0;
    for (int i = 0; i < length; i++) {
        if (string[i] == ' ') {
            currentWord++;
            currentWordIndex = 0;
        }
        else {
            words[currentWord][currentWordIndex] = string[i];
            currentWordIndex++;
        }
    }
    char *result = (char *) malloc(sizeof(char) * length);
    for (int i = 0; i < nWords; i++) {
        strcat(result, words[nWords - i - 1]);
        strcat(result, " ");
    }
    result[length] = 0;

    return result;
}