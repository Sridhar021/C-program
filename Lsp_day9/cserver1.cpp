#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
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
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen=sizeof(address);
	
	

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

	std::cout<<"Client connected"<<std::endl;

	receiveFile(new_socket, "received_from_client.txt");
	std::cout<<"File received from client and saved as 'received_from_client.txt' "<<std::endl;

	sendFile(new_socket, "send_to_client.txt");
	std::cout<<"File 'send_to_client.txt' sent to client"<<std::endl;
	close(new_socket);
	close(server_fd);

	return 0;
}

