#include<iostream>
#include<fstream>
#include<cstring>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	int sock =0;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	std::string file_path;
	
	std::cout<<"Enter the file to send: ";
	std::getline(std::cin, file_path);

	std::ifstream file(file_path, std::ios::binary);
	if(!file.is_open()) {
		std::cerr<<"Failed to open file: "<<file_path<<std::endl;
		return -1;
	}
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
	
	std::string file_name = file_path.substr(file_path.find_last_of("/\\") + 1);
	//send message to server
	send(sock, file_name.c_str(), file_name.size(), 0);

	while(file.good()) {
		file.read(buffer, sizeof(buffer));
		if(file.gcount() > 0) {
			send(sock, buffer, file.gcount(), 0);
		}
	}
	
	file.close();
	close(sock);
	std::cout<<"File sent successfully: "<<file_name<<std::endl;

	

	return 0;
}
