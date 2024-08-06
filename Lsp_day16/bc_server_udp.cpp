#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	int sockfd;
	struct sockaddr_in bcAddr;
	const char *bcIP = "255.255.255.255";
	int bcPort = 8080;
	const char* message = "Broadcasting message...";

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		std::cerr<<"Socket creation failed"<<std::endl;
		return -1;
	}

	int bcPer = 1;
	if(setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &bcPer, sizeof(bcPer)) < 0) {
		std::cerr<<"Setting broadcast permission failed"<<std::endl;
		close(sockfd);
		return -1;
	}

	memset(&bcAddr, 0, sizeof(bcAddr));
	bcAddr.sin_family = AF_INET;
	bcAddr.sin_addr.s_addr = inet_addr(bcIP);
	bcAddr.sin_port = htons(bcPort);

	if(sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&bcAddr, sizeof(bcAddr)) < 0) {
		std::cerr<<"Broadcast send failed"<<std::endl;
		close(sockfd);
		return -1;
	}

	std::cout<<"Broadcast message sent"<<std::endl;

	close(sockfd);
	return 0;
}


