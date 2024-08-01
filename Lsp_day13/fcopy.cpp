#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

int main(int argc, char* argv[]) {
	const char* sfile = argv[1];
	const char* dfile = argv[2];

	int sfd = open(sfile, O_RDONLY);
	if(sfd ==-1) {
		std::cerr<<"Error opening source file:"<<strerror(errno)<<std::endl;
		return 1;
	}

	int dfd = open(dfile, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if(dfd ==-1) {
                std::cerr<<"Error opening destination file:"<<strerror(errno)<<std::endl;
		close(sfd);
                return 1;
        }
	
	const int bsize = 1024;
	char buffer[bsize];
	ssize_t bytesread, byteswrite;

	while((bytesread = read(sfd, buffer, bsize)) > 0) {
		byteswrite = write(dfd, buffer, bytesread);
		if(byteswrite ==-1) {
                std::cerr<<"Error writing to destination file:"<<strerror(errno)<<std::endl;
                close(sfd);
		close(dfd);
		return 1;
        	}
	}

	if(bytesread ==-1) {
                std::cerr<<"Error reading file:"<<strerror(errno)<<std::endl;
                
        }

	if(close(sfd) ==-1) {
                std::cerr<<"Error closing source file:"<<strerror(errno)<<std::endl;

        }
	if(close(dfd) ==-1) {
                std::cerr<<"Error closing destination file:"<<strerror(errno)<<std::endl;

        }

	return 0;
}

