#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
#include<arpa/inet.h>
#include<fstream>

#define PORT 65432
#define BUFFER_SIZE 1024

void sendFile(int socket, const std::string &filename) {
        std::ifstream file(filename, std::ios::binary);
        if(!file) {
                std::cerr<<"Unable to open file: "<<filename<<std::endl;
                return;
        }

        char buffer[BUFFER_SIZE];
        while(file.read(buffer, sizeof(buffer))) {
                send(socket, buffer, file.gcount(), 0);
        }

        send(socket, buffer, file.gcount(), 0);
        file.close();
}

void receiveFile(int socket, const std::string &filename) {
        std::ofstream file(filename, std::ios::binary);
        if(!file) {
                std::cerr<<"Unable to open file: "<<filename<<std::endl;
                return;
        }

        char buffer[BUFFER_SIZE];
        int bytesReceived=0;
        while((bytesReceived= read(socket, buffer, BUFFER_SIZE)) > 0) {
                file.write(buffer, bytesReceived);
        }
        file.close();
}

int main() {
	int sock=0;
	struct sockaddr_in serv_addr;
	
	std::ofstream file("send_to_server.txt");
	if(file.is_open()) {
		file << "Hello, server! This is a message from client.";
		file.close();
	}
	else {
		std::cerr<<"Unable to open file to write"<<std::endl;
		return -1;
	}

	if((sock=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cout<<"Socket creation error"<<std::endl;
		return -1;
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port= htons(PORT);

	if(inet_pton(AF_INET, "172.20.0.16", &serv_addr.sin_addr) <= 0) {
		std::cout<<"Invalid address/Address not supported"<<std::endl;
		return -1;
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		std::cout<<"Connection Failed"<<std::endl;
		return -1;
	}
	
	sendFile(sock, "send_to_server.txt");
	std::cout<<"File 'send_to_server.txt' sent to server"<<std::endl;

	receiveFile(sock, "received_from_server.txt");
	std::cout<<"File received from server and saved as 'received_from_server.txt' "<<std::endl;

	
	close(sock);
	return 0;
}


