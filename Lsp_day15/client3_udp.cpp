#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <fstream>
#define DEFAULT_PORT 8080
#define DEFAULT_BUFLEN 512

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char sendbuf[DEFAULT_BUFLEN];
    char recvbuf[DEFAULT_BUFLEN];
    socklen_t serverAddrLen = sizeof(serverAddr);

    // Create a socket for the client
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Set up the sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(DEFAULT_PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    std::ifstream inFile("send.txt", std::ios::binary);
    if(!inFile) {
	    std::cerr<<"File not found"<<std::endl;
	    close(clientSocket);
	    return 1;
    }

    while(inFile) {
	    inFile.read(sendbuf, DEFAULT_BUFLEN);
	    int bytesread = inFile.gcount();

	    if(bytesread > 0) {

    		// Send data to the server
    		int sendLen = sendto(clientSocket, sendbuf, strlen(sendbuf), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    		if (sendLen < 0) {
        		std::cerr << "sendto failed" << std::endl;
        		close(clientSocket);
			inFile.close();
        		return 1;
    		}
	    }
    }
	

    sendto(clientSocket, "", 0, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    std::cout << "File sent successfully. Waiting to receive response " << std::endl;

    std::ofstream outFile("received_back_file.txt", std::ios::binary);
    if(!outFile) {
            std::cerr<<"File creation failed"<<std::endl;
            close(clientSocket);
            return 1;
    }

    // Receive data
    while (true) {
        int recvLen = recvfrom(clientSocket, recvbuf, DEFAULT_BUFLEN, 0, (struct sockaddr*)&serverAddr, &serverAddrLen);
        if (recvLen < 0) {
            std::cerr << "recvfrom failed" << std::endl;
            close(clientSocket);
	    outFile.close();
            return 1;
        }

        if(recvLen == 0) {
                break;
        }
        outFile.write(recvbuf, recvLen);
    }
    std::cout << "File received back from server successfully. " << std::endl;
	

    // Cleanup
    close(clientSocket);
    outFile.close();
    return 0;
}
