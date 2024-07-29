#include<iostream>
#include<mqueue.h>
#include<cstring>
#include<cstdlib>
#include<cerrno>
#include<cstdio>


#define QUEUE_NAME1 "/test_queue1"
#define QUEUE_NAME2 "/test_queue2"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

int main() {
	mqd_t mq1, mq2;
	struct mq_attr attr;
	char buffer[MAX_SIZE];

	attr.mq_flags=0;
	attr.mq_maxmsg=10;
	attr.mq_msgsize= MAX_SIZE;
	attr.mq_curmsgs=0;

	mq1 = mq_open(QUEUE_NAME1, O_CREAT | O_RDONLY, 0664, &attr);
	mq2 = mq_open(QUEUE_NAME2, O_CREAT | O_WRONLY, 0664, &attr);
	if(mq1 == -1 || mq2 == -1) {
		std::cerr<<"Error creating queue: "<<strerror(errno)<<std::endl;
		exit(1);
	}
	
	while(true) {
	ssize_t bytes_read = mq_receive(mq1, buffer, MAX_SIZE, nullptr);
        if(bytes_read == -1) {
                std::cerr<<"Error receiving message: "<<strerror(errno)<<std::endl;
                exit(1);
        }
	buffer[bytes_read] = '\0';
        std::cout<<"Process2 received: "<<buffer<<std::endl;
	
	if(strcmp(buffer, MSG_STOP) == 0)
	{
		break;
	}

	std::cout<<"Process2, Enter a message: ";
	std::cin.getline(buffer, MAX_SIZE);

	if(mq_send(mq2, buffer, strlen(buffer) + 1, 0) == -1) {
			std::cerr<<"Error sending message: "<<strerror(errno)<<std::endl;
			exit(1);
		}
	}
	

	mq_close(mq1);
	mq_close(mq2);
	mq_unlink(QUEUE_NAME1);
	mq_unlink(QUEUE_NAME2);

	return 0;
}


