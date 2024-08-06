#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	int sock =0;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	std::string message;

	//create socket fd
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		std::cerr<<"Socket creation error"<<std::endl;
		return -1;
	}
	
	//set server address
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);

	if(inet_pton(AF_INET, "172.20.0.16", &serv_addr.sin_addr) <= 0) {
		std::cerr<<"Invalid connection"<<std::endl;
		return -1;
	}

	//connect to server
	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		std::cerr<<"Connection failed"<<std::endl;
		return -1;
	}

	std::cout<<"Enter message ";
	std::getline(std::cin, message);

	//send message to server
	send(sock, message.c_str(), message.size(), 0);

	int valread = read(sock, buffer, 1024);
	std::cout<<"Echoed message: "<<buffer<<std::endl;

	close(sock);

	return 0;
}
