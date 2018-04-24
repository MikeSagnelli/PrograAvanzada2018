#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
    char *serverName = argv[1];
    struct hostent *serverIp;
    struct sockaddr_in server;
    char *msg = "GET/1.0\r\n Host: 10.43.32.108 \r\n";
    char buffer[1000];
    int my_socket;
    serverIp = gethostbyname(serverName);
    memcpy(&server.sin_addr, serverIp->h_addr_list[0], serverIp->h_length);
    server.sin_port = htons(443);
    server.sin_family = AF_INET;
    my_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(my_socket, (struct sockaddr *)&server, sizeof(server)) == 0){
        printf("CONNECTED \n");
        write(my_socket, msg, sizeof(msg));
        read(my_socket, buffer, sizeof(buffer));
        printf("Data: %s \n", buffer);
    }
    else{
        printf("Error connecting %d\n", errno);
    }
    printf("The ip address is: %s\n",serverIp->h_name);
    return 0;
}