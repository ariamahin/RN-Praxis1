
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define BACKLOG 10
#define MYPORT "1234"


int main(int argc, char** argv) {

    // Start here :)

    struct addrinfo hints, *res;
    socklen_t address_length;
    struct sockaddr_in serverAddress;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype= SOCK_STREAM;
    hints.ai_flags= AI_PASSIVE;

    getaddrinfo(NULL, MYPORT, &hints, &res);

    int serverSocket = socket(res ->ai_family, res ->ai_socktype, res->ai_protocol);

    bind(serverSocket, res->ai_addr, res->ai_addrlen);

    connect(serverSocket, res->ai_addr, res->ai_addrlen);

    listen(serverSocket, BACKLOG);

    address_length= sizeof(serverAddress);

    int new_server= accept(serverSocket,(struct sockaddr* ) &serverAddress,(socklen_t *)&address_length);

    char *msg = "Reply\n";
    int len, bytes_sent;

    len= strlen(msg);
    bytes_sent = send(new_server,msg,len, 0);

    return EXIT_SUCCESS;
};

    // Listen on the socket
    //int listening = listen(serverSocket, backlog);
    //if (listening < 0){
      //  printf("Der server ist nicht erreichbar!\n");
       // return 1;
        //}

    // Accept a connection & wait for a connection
   // while(1) {
     //   clientSocket = accept(serverSocket, NULL, NULL);
      //  send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        //close(clientSo

