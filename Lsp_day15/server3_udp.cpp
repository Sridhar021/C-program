#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <fstream>

#define DEFAULT_PORT 8080
#define DEFAULT_BUFLEN 512

int main() {
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Create a socket for the server
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Set up the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(DEFAULT_PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::ofstream outFile("received_file.txt", std::ios::binary);
    if(!outFile) {
	    std::cerr<<"File creation failed"<<std::endl;
	    close(serverSocket);
	    return 1;
    }

    // Receive data
    while (true) {
        int recvLen = recvfrom(serverSocket, recvbuf, recvbuflen, 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (recvLen < 0) {
            std::cerr << "recvfrom failed" << std::endl;
            close(serverSocket);
            return 1;
        }

        if(recvLen == 0) {
		break;
	}
	outFile.write(recvbuf, recvLen);
    }
    std::cout << "File received successfully. " << std::endl;
    outFile.close();
    std::ifstream inFile("received_file.txt", std::ios::binary);
	if(!inFile) {
		std::cerr<<"File not found for sending back"<<std::endl;
	close(serverSocket);
	return 1;
	}
	
    while(inFile) {
    	inFile.read(recvbuf, DEFAULT_BUFLEN);
            int bytesread = inFile.gcount();

            if(bytesread > 0) {

                // Send data to the server
                int sendLen = sendto(serverSocket, recvbuf, bytesread, 0, (struct sockaddr*)&clientAddr, clientAddrLen);
                if (sendLen < 0) {
                        std::cerr << "sendto failed" << std::endl;
                        close(serverSocket);
                        inFile.close();
                        return 1;
                }
            }
    }

    sendto(serverSocket, "", 0, 0, (struct sockaddr*)&clientAddr, clientAddrLen);
    std::cout << "File sent back to client successfully. " << std::endl;
	    
        

    // Cleanup
    close(serverSocket);
    inFile.close();
    return 0;
}
