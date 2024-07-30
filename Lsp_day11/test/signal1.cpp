#include<iostream>
#include<csignal>
#include<unistd.h>

using namespace std;

void handle_sigint(int sig) {
	cout<<"Caught signal "<<sig<<" SIGINT. Terminating gracefully..."<<endl;
	exit(0);
}

void handle_sigterm(int sig) {
        cout<<"Caught signal "<<sig<<" SIGTERM. Terminating gracefully..."<<endl;
        exit(0);
}

void handle_sigusr1(int sig) {
        cout<<"Caught signal "<<sig<<" SIGUSR1. Terminating gracefully..."<<endl;
        exit(0);
}


int main() {
	struct sigaction sa_int, sa_term, sa_usr1;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, nullptr);
	
	sa_term.sa_handler = handle_sigterm;
        sigemptyset(&sa_term.sa_mask);
        sa_term.sa_flags = 0;
        sigaction(SIGTERM, &sa_term, nullptr);

	sa_usr1.sa_handler = handle_sigusr1;
        sigemptyset(&sa_usr1.sa_mask);
        sa_usr1.sa_flags = 0;
        sigaction(SIGUSR1, &sa_usr1, nullptr);


	cout<<"Program running. Send signal"<<endl;

	while(true) {
		cout<<"Running..."<<endl;
		sleep(1);
	}
	return 0;
}

