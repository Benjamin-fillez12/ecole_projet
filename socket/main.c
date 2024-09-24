#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

#pragma comment(lib,"ws2_32.lib")

int main(){
    WSADATA data;
    if(WSAStartup(MAKEWORD(2,2),&data) != 0){
        fprintf(stderr,"Erreur durant l'initialisation de ws2_32.dll\nRaison:%s",strerror(WSAGeLastError()));
        return 1;
    };

    struct serveraddr_in serverAdress;
    SOCKET serverSock;
    if(serverSock = socket(AF_INET,SOCK_STREAM,0) == INVALID_SOCKET){
        fprintf(stderr,"Impossible de crée le socket\nRaison:%s",strerror(WSAGeLastError()));
        WSACleanup();
        return 1
    };
    
    memset(&serverAdress,0,sizeof(serverAdress));
    serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(8080);

    if((bind(serverSock,(SOCKADDR *)&serverAdress,sizeof(serverAdress))) == SOCKET_ERROR){
        fprintf(
            stderr,
            "Fonction \"bind\" a causer une erreur\nErreur: %s\n",
            strerror(WSAGeLastError())
        );
        closesocket(serverSock);
        free(serverSock);
        WSACleanup();
    };

    if(connect(serverSock,(struct sockaddr *)&serverAdress,sizeof(serverAdress)) < 0){
        fprintf(
            stderr,
            "Connection impossible\nAppuyez sur n'importe quel touches pour quitter\nErreur:%s\n",
            strerror(WSAGeLastError())    
        );
        closesocket(serverSock);
        free(serverAdress);
        WSACleanup();
        return 1;
    };

    closesocket(serverSock);
    free(serverAdress);
    WSACleanup();
    return 0;
}
