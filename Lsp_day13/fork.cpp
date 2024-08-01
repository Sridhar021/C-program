#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main() {
	pid_t pid = fork();

	if(pid < 0) {
		cerr<<"Fork failed"<<endl;
		return 1;
	} else if(pid == 0) {
		execl("/bin/ls", "ls", "-l", nullptr);
		cerr<<"Exec failed"<<endl;
		return 1;
	} else {
		wait(nullptr);
		cout<<"Child process completed"<<endl;
	}
	return 0;
}
