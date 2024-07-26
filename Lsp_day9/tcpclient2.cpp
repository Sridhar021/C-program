#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
#include<errno.h>

#define PORT 5050

int main() {
	int sock=0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024]={0};
	std::string message;

	if((sock=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cout<<"Socket creation error"<<std::endl;
		return -1;
	}

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port= htons(PORT);

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		std::cout<<"Invalid address/Address not supported"<<std::endl;
		return -1;
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		std::cout<<"Connection Failed"<<std::endl;
		return -1;
	}
	std::cout<<"Connected to server on port "<<PORT<<std::endl;

	std::cout<<"Enter message: ";
	std::getline(std::cin, message);
	
	ssize_t bytes_sent= send(sock, message.c_str(), message.length(), 0);
	if(bytes_sent < 0) {
		perror("Send error");
		close(sock);
		return -1;
	}
	
	std::cout<<"Message sent to server"<<std::endl;
	ssize_t bytes_received= read(sock, buffer, 1024);
	if(bytes_received < 0) {
		perror("Received error");
		close(sock);
		return -1;
	} else if(bytes_received == 0) {
		std::cerr<<"Server closed connection"<<std::endl;
	} else {
		buffer[bytes_received] = '\0';
		std::cout<<"Message from server: "<<buffer<<std::endl;
	}
	
	close(sock);
	return 0;
}


