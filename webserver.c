#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>

// erstellen der Serverstruktur
struct Server{
    int port;
};


int main(int argc, char** argv) {

    // Start here :)
    int port = port; //port wird von Client übergeben(Aufgabenstellung)

    // Create socket:af: address Family, type: specification for the new socket, protocol
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);


    // Construct local address structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8000);//port wird von Client übergeben(Aufgabenstellung)
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);


    //teste ob server verbunden ist --> sonst verlasse mit 1 (standart Fehlerrückgabe)
    if(serverSocket == 0){
        perror("Failes to connect socket...\n");
        exit(1);
    }

    // binde mit server --> teste ob Rückgabe von bind kleiner 0 (-1) dann error
    if(bind(serverSocket, (struct sockaddr*) &serverAddress,sizeof(serverAddress)) < 0){
        perror("Failed to bind \n");
        exit(1); // exit mit 1
    }

    //höre client zu
    // zweiter int gibt an wie viele sich anstellen, hier erstmal von mir auf 10
    //festgelegt bis weiteres bekannt
    // + test (listen gibt bei fail auch -1 zurück)
    if((listen(serverSocket,10)) < 0){
        perror("Failed to listen...\n");
        exit(1);
    }
    // den server akzeptieren
    char buffer[3000];
    int address_length= sizeof(serverAddress);
    accept(serverSocket,(struct sockaddr* ) &serverAddress,(socklen_t *)&address_length);
    printf("%s\n",buffer);


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
        //close(clientSocket);

