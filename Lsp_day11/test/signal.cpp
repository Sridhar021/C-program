#include<iostream>
#include<csignal>
#include<unistd.h>

using namespace std;

void handle_sigint(int sig) {
	cout<<"Caught signal "<<sig<<" SIGINT. Terminating gracefully..."<<endl;
	exit(0);
}

int main() {
	signal(SIGINT, handle_sigint);
	cout<<"Program running. Press Ctrl+c to terminate"<<endl;

	while(true) {
		cout<<"Running..."<<endl;
		sleep(1);
	}
	return 0;
}

