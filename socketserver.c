#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket( int hSocket ) {
    int iRetval = -1;
    int clientPort = 12345;
    
    struct sockaddr_in remote = {0};
    
    /* Internet address familiy */
    remote.sin_family = AF_INET;
    
    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort); /* Local port */
    
    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main_socketserver() {

    int socket_desc = 0, sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};
    const char *pMessage = "hello from Jason's server";
    
    /* Create socket */
    socket_desc = socketCreate();
    if ( socket_desc == -1 ) {
        printf( "Could not create socket\n" );
        return -1;
    }
    printf( "Socket created\n" );
    
    /* Bind */
    if ( bindCreatedSocket( socket_desc ) < 0 ) {
        perror( "bind failed.");
        return 1;
    }
    printf( "bind done\n" );
    
    listen(socket_desc, 3); /* max 3 clients to wait */
    
    /* Accept incoming connection */
    
    while(1) {
        printf("Waiting for incoming connections...\n");
        clientLen = sizeof(struct sockaddr_in);
        
        /* acccept connection from an incoming client */
        sock = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&clientLen);
        
        if( sock < 0 ) {
            perror( "accept failed" );
            return 1;
        }
        printf( "Connection accepted\n" );
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);
        
        /* Receive a reply from the client */
        if( recv(sock, client_message, 200, 0 ) < 0 ) {
            printf( "recv failed" );
            break;
        }
        printf( "Client reply: %s\n", client_message );
        
        if(strcmp(pMessage, client_message) == 0) {
            strcpy(message, "Hi there !");
        }
        else {
            strcpy(message, "Invalid Message !");
        }
        
        /* Send some data */
        if( send(sock, message, strlen(message), 0) < 0 ) {
            printf( "Send failed" );
            return 1;
        }
        close(sock);
        sleep( 1 );
    }
    return 0;
}