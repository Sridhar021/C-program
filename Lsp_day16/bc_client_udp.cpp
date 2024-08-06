#include<iostream>
#include<cstring>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
	int sockfd;
	struct sockaddr_in lAddr;
	char buffer[1024];
	int bcPort = 8080;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
                std::cerr<<"Socket creation failed"<<std::endl;
                return -1;
        }

	memset(&lAddr, 0, sizeof(lAddr));
        lAddr.sin_family = AF_INET;
        lAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        lAddr.sin_port = htons(bcPort);

	if(bind(sockfd, (struct sockaddr *)&lAddr, sizeof(lAddr)) < 0) {
			std::cerr<<"Bind failed"<<std::endl;
			close(sockfd);
			return -1;
	}

	std::cout<<"Listening for broadcast message on port " <<bcPort<<std::endl;

	while(true) {
		socklen_t addr_len = sizeof(lAddr);
		int bytesrecv = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&lAddr, &addr_len);
		if(bytesrecv < 0) {
			std::cerr<<"Receive failed"<<std::endl;
			continue;
		}

		buffer[bytesrecv] = '\0';
		std::cout<<"Received broadcast message: "<<buffer<<std::endl;
	}

	close(sockfd);
	return 0;
}


