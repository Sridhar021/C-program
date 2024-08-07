#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>

#define PORT 8080

int main() {
	int sock=0, valread;
	struct sockaddr_in serv_addr;
	const char *hello= "Hello from client";
	char buffer[1024]={0};

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

	send(sock, hello, strlen(hello), 0);
	std::cout<<"Hello message sent \n";
	valread=read(sock, buffer, 1024);
	std::cout<<"Message from server: "<<buffer<<std::endl;
	close(sock);
	return 0;
}


