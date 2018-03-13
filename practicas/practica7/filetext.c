#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printDebug(...) do{ \
    char message[255];\
    char *isDebug;\
    isDebug = getenv("DEBUG");\
    if(isDebug != NULL && !strcasecmp(isDebug,"y")){\
        fprintf(stderr,__VA_ARGS__);\
    }\
}while(0)

int main(){
	char *filename = "output.txt";
	FILE *output;
	int character;
	output = fopen(filename, "a");
	printDebug("output = %p\n",output);
	while(1){
		character = fgetc(stdin);
		if(feof(stdin)){
			break;
		}
		fputc(character,output);
	};
	fclose(output);
	return 0;
}