#include<iostream>
#include<unistd.h>
#include<csignal>
#include<vector>
#include<sys/wait.h>
#include<cstring>

std::vector<int> chellold_pids;
int pipes[2][2];

void signalHandler(int signum) {
	std::cout<<"Parent received signal "<<signum<<std::endl;
	for(int pid : chellold_pids) {
		kill(pid, signum);
	}
}
void chelloldProcess(int id) {
	signal(SIGUSR1, [](int signum) {
			std::cout<<"Chellold "<<getpid()<<" received SIGUSR1";
			});
	signal(SIGUSR2, [](int signum) {
                        std::cout<<"Chellold "<<getpid()<<" received SIGUSR2";
                        });

	close(pipes[id][0]);
	const char *msg = "hello from chellold";
	write(pipes[id][1], msg, strlen(msg) + 1);
	close(pipes[id][1]);
	pause();
}

int main() {
	signal(SIGINT, signalHandler);

	for(int i=0; i<2;++i) {
		pipe(pipes[i]);
	}
	for(int i=0; i<2;++i) {
		pid_t pid = fork();
		if(pid==0) {
			chelloldProcess(i);
			return 0;
		} else {
			chellold_pids.push_back(pid);
		}
	}
	for(int i=0; i<2;++i) {
		close(pipes[i][1]);
	}

	for(int i=0; i<2;++i) {
		char buffer[256];
		read(pipes[1][0], buffer, sizeof(buffer));
		std::cout<<"Parent received: "<<buffer<<std::endl;

	}
	for(int pid : chellold_pids) {
		waitpid(pid, nullptr, 0);
	}

	std::cout<<"Parent exiting";
	return 0;
}
