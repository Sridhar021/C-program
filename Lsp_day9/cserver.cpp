#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<cstring>
#include<arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

int main() {
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen=sizeof(address);
	char buffer[BUFFER_SIZE]= {0};
	

	if((server_fd= socket(AF_INET, SOCK_STREAM, 0)) == 0){
			perror("socket failed");
			exit(EXIT_FAILURE);
	}
	


	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("172.20.0.16");
	address.sin_port=htons(PORT);

	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
	perror("Bind failed");
	close(server_fd);
	exit(EXIT_FAILURE);
	}

	if(listen(server_fd, 3) < 0) {
	perror("Listen");
	close(server_fd);
	exit(EXIT_FAILURE);
	}
	std::cout<<"Server listening on ip 172.20.0.16 : "<<PORT<<std::endl;

	if((new_socket= accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
		perror("Accept");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	while(true) {
		memset(buffer, 0, BUFFER_SIZE);
		int valread = read(new_socket, buffer, BUFFER_SIZE);
		if(valread <= 0) {
			break;
		}
		std::cout<<"Received from client: " <<buffer<<std::endl;
		send(new_socket, buffer, strlen(buffer), 0);
	}
	close(new_socket);
	close(server_fd);

	return 0;
}

