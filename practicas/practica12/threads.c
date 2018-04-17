#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 20

void *helloThread(void *){
    printf("Hello world!");
}

int main(){
    pthread_t threads[MAX_THREADS];
    for(int i = 0; i < MAX_THREADS; i++){
        pthread_create(
            &threads[i],
            NULL,
            helloThread,
            NULL
        );
    }
    return 0;
}