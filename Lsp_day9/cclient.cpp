#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
#include<arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

int main() {
	int sock=0;
	struct sockaddr_in serv_addr;
	char buffer[BUFFER_SIZE]={0};

	if((sock=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cout<<"Socket creation error"<<std::endl;
		return -1;
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port= htons(PORT);

	if(inet_pton(AF_INET, "172.20.0.57", &serv_addr.sin_addr) <= 0) {
		std::cout<<"Invalid address/Address not supported"<<std::endl;
		return -1;
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		std::cout<<"Connection Failed"<<std::endl;
		return -1;
	}
	
	while(true) {
		std::cout<<"Enter message to send (type 'exit' to close): ";
		std::string message;
		std::getline(std::cin, message);
		if(message == "exit") {
			break;
		}
		
		send(sock, message.c_str(), message.length(), 0);
		std::cout<<"Message sent"<<std::endl;

		memset(buffer, 0, BUFFER_SIZE);
		int valread = read(sock, buffer, BUFFER_SIZE);
		std::cout<<"Received from server: "<<buffer<<std::endl;
	}

	
	close(sock);
	return 0;
}


