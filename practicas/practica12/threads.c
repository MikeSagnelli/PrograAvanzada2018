#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 20

int global = 5;

void *helloThread(void * arg){
    long id = (long)arg;
    global = id * global;
    printf("Hello world! %ld\n", id);
    return NULL;
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
    for(int i = 0; i < MAX_THREADS; i++){
        pthread_join(
            thread[i],
            NULL
        );
    }
    return 0;
}