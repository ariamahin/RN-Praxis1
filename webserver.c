#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>


typedef struct res res;

int main(int argc, char** argv) {
    // Start here :)

    // Create socket:af: address Family, type: specification for the new socket, protocol
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    printf("Reply\r\n");


    // Construct local address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8001);
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    //get address info
    struct addrinfo hints, *res;
    getaddrinfo(NULL, "3490", 0, &res);

    // Bind the socket
    //int size= sizeof(serverAddress);

    //bind(serverSocket, (struct sockaddr*) &server_address, sizeof(server_address));
    int binding = bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);

    // Listen on the socket
    int listening = listen(serverSocket, backlog);
    if (listening < 0){
        printf("Der server ist nicht erreichbar!\n");
        return 1;
        }

    // Accept a connection & wait for a connection
    while(1) {
        clientSocket = accept(serverSocket, NULL, NULL);
        send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        close(clientSocket);
    }
    return 0;

    // connect
    int connect(int socket, const struct sockaddr *address, socklen_t address_len){

    }
    //address info
    int getaddrinfo( const char *hostname, const char *servname, const char *servname, const struct addrinfo *hints, struct addrinfo **res){

    }
    int send(){

    }
    int recv(){

    }

    int close(){

    }

    return EXIT_SUCCESS;
}
