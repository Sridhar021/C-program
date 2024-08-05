#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>


#define DEFAULT_BUFLEN 512

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    socklen_t serverAddrLen = sizeof(serverAddr);
    
    char serverIP[INET_ADDRSTRLEN];
    int serverPort;
    std::cout<<"Enter server IP address: ";
    std::cin>>serverIP;
    std::cout<<"Enter server port number: ";
    std::cin>>serverPort;

    // Create a socket for the client
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Set up the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    if(inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
	    std::cerr<<"Invalid address "<<std::endl;
	    close(clientSocket);
	    return 1;
    }

    // Send data to the server
    const char* message = "Hello, Server";
    int sendLen = sendto(clientSocket, message, strlen(message), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (sendLen < 0) {
        std::cerr << "sendto failed" << std::endl;
        close(clientSocket);
        return 1;
    }

    

    // Receive data from the server
    int recvLen = recvfrom(clientSocket, recvbuf, recvbuflen, 0, (struct sockaddr*)&serverAddr, &serverAddrLen);
    if (recvLen < 0) {
        std::cerr << "recvfrom failed" << std::endl;
        close(clientSocket);
        return 1;
    }

    recvbuf[recvLen] = '\0'; // Null-terminate the received data
    std::cout << "Server acknowledgment: " << recvbuf << std::endl;

    // Cleanup
    close(clientSocket);
    return 0;
}
