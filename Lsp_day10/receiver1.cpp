#include<iostream>
#include<mqueue.h>
#include<cstring>
#include<cstdlib>
#include<cerrno>
#include<cstdio>

#define QUEUE_NAME "/test_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

int main() {
        mqd_t mq;
        struct mq_attr attr;
        char buffer[MAX_SIZE + 1];
	ssize_t bytes_read;

	attr.mq_flags=0;
        attr.mq_maxmsg=10;
        attr.mq_msgsize= MAX_SIZE;
        attr.mq_curmsgs=0;

	mq = mq_open(QUEUE_NAME, O_RDONLY);
        if(mq == -1) {
                std::cerr<<"Error opening queue: "<<strerror(errno)<<std::endl;
                exit(1);
        }
	while(true) {
	bytes_read = mq_receive(mq, buffer, MAX_SIZE, nullptr);
	if(bytes_read == -1) {
		std::cerr<<"Error receiving message: "<<strerror(errno)<<std::endl;
		exit(1);
	}

	buffer[bytes_read] = '\0';
	std::cout<<"Received message: "<<buffer<<std::endl;
	if(strcmp(buffer, MSG_STOP) == 0) {
		break;
		}
	}
	mq_close(mq);
	mq_unlink(QUEUE_NAME);

	return 0;
}




