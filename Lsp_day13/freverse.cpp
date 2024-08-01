#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

void reverse(char* str, size_t length) {
	size_t start = 0;
	size_t end = length - 1;
	while(start < end) {
		std::swap(str[start], str[end]);
		start++;
		end--;
	}
}


int main(int argc, char* argv[]) {
	const char* filepath = argv[1];

	int fd = open(filepath, O_RDWR);
	if(fd ==-1) {
	 	std::cerr<<"Error opening file: "<<strerror(errno)<<std::endl;
		return 1;
	}

	const int bsize = 1024;
	char buffer[bsize];
	char lbuffer[bsize];
	size_t bytesread;
	size_t llength=0;
	off_t offset=0;

	while((bytesread = read(fd, buffer, bsize)) > 0) {
		for(ssize_t i=0; i<bytesread;++i) {
			lbuffer[llength++] = buffer[i];
			if(buffer[i] == '\n' || (i == bytesread - 1 && buffer[i] != '\n')) {
				if(lbuffer[llength -1] == '\n') {
					llength--;
				}

				reverse(lbuffer, llength);

				if(lseek(fd, offset, SEEK_SET) == -1) {
                			std::cerr<<"Error seeking in file: "<<strerror(errno)<<std::endl;
					close(fd);
                			return 1;
				}
				if(write(fd, lbuffer, llength) ==-1) {
					std::cerr<<"Error writing to file: "<<strerror(errno)<<std::endl;
                			close(fd);
					return 1;
        			}
				
				if(buffer[i] == '\n') {
					if(write(fd, "\n", 1) ==-1) {
                				std::cerr<<"Error writing newline to file: "<<strerror(errno)<<std::endl;
                				close(fd);
						return 1;
					}
				offset += llength +1;
				} else {
				offset += llength;
				}
			llength = 0;
			}
		}
	}



	if(bytesread ==-1) {
                std::cerr<<"Error reading file:"<<strerror(errno)<<std::endl;
                close(fd);
		return 1;
        }

	if(close(fd) ==-1) {
                std::cerr<<"Error closing file:"<<strerror(errno)<<std::endl;

        }

	return 0;
}

