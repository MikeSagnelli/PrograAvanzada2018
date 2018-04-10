#include <signal.h>
#include <unistd.h>

void receiveSignal(int sig){
    printf("HOLA MUNDO\n");
    printf("Recibi sennal %d\n", sig);
}

int main(){
    signal(SIGTERM, receiveSignal);
    while(1){

    }
    return 0;
}