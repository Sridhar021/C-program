#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main() {
	int server_fd, client_fd;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	
	//create socket file descriptor
	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) ==0) {
		std::cerr<<"Socket failed"<<std::endl;
		return -1;
	}
	//set server address
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	
	//bind socket to address
	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		std::cerr<<"Bind failed"<<std::endl;
		close(server_fd);
		return -1;
	}
	//listen for incoming connections
	if(listen(server_fd, 3) < 0) {
		std::cerr<<"Listen faile"<<std::endl;
		close(server_fd);
		return -1;
	}

	std::cout<<"Server is listening on port 8080 "<<std::endl;
	
	//run server on loop
	while(true) {
		//accept new connection
		if((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
			std::cerr<<"Accept failed"<<std::endl;
			close(server_fd);
			return -1;
		}
		
		//read message from client
		int valread = read(client_fd, buffer, 1024);
		std::cout<<"Received: "<<buffer<<std::endl;
		
		//echo message back to client
		send(client_fd, buffer, valread, 0);
		
		//clear 
		memset(buffer, 0, sizeof(buffer));
		
		//close client connection
		close(client_fd);
	}
	
	//close server socket
	close(server_fd);
	return 0;
}
