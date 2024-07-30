#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/wait.h>
#define B_SIZE 128

int main() {
	int pipefd[2];
	pid_t pid;
	char buffer[B_SIZE];

	if(pipe(pipefd) == -1) {
		perror("pipe");
		return 1;
	}

	pid = fork();
	if(pid == -1) {
		perror("fork");
		return 1;
	}

	if(pid == 0) {
		close(pipefd[1]);
		ssize_t bytesread = read(pipefd[0], buffer, B_SIZE);
		if(bytesread == -1) {
			perror("read");
		} else {
			std::cout<<"Child received:"<<buffer<<std::endl;
		}
		close(pipefd[0]);
	}
	else {
		close(pipefd[0]);

		const char *message = "Hello from parent";
		ssize_t byteswrite = write(pipefd[1], message, strlen(message) + 1);
		if(byteswrite == -1) {
			perror("write");
		}
		close(pipefd[1]);
		wait(NULL);
	}
	return 0;
}

