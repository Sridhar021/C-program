#include<iostream>
#include<unistd.h>

using namespace std;

int main() {
	char *args[] = {"/bin/ls", "-l", nullptr};

	if(execvp(args[0], args) == -1) {
		cerr<<"Error executing command:"<<errno<<endl;
		return 1;
	}
	cerr<<"This should not be printed"<<endl;
	return 0;
}

