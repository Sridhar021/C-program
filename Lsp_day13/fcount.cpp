#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<cctype>

int main(int argc, char* argv[]) {
	const char* filep = argv[1];

	int fd = open(filep, O_RDONLY);
	if(fd == -1) {
		std::cerr<<"Error opening file: "<<strerror(errno)<<std::endl;
		return 1;
	}

	const int bsize = 1024;
	char buffer[bsize];
	ssize_t bytesread;
	int wc = 0;
	bool inword = false;

	while((bytesread = read(fd, buffer, bsize)) > 0) {
		for(ssize_t i =0; i < bytesread; ++i) {
			if(std::isspace(buffer[i])) {
				if(inword) {
					inword = false;
					wc++;
				}
			} else {
				if(!inword) {
					inword = true;
				}
			}
		}
	}

	if(inword) {
		wc++;
	}

	if(bytesread == -1) {
                std::cerr<<"Error reading from file: "<<strerror(errno)<<std::endl;
                close(fd);
		return 1;
        }
	if(close(fd) == -1) {
                std::cerr<<"Error closing file: "<<strerror(errno)<<std::endl;
                
        }
	std::cout<<"Word count: "<<wc<<std::endl;
	return 0;
}

