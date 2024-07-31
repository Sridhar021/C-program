#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<cerrno>

int main() {
	const char* fname = "example.txt";
	const char* text = "Hello, World!";
	char buffer[256];
	ssize_t b_write, b_read;
	int fd;

	fd = open(fname, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if(fd == -1) {
		std::cerr<<"Error opening file: "<<strerror(errno)<<std::endl;
		return 1;
	}

	b_write = write(fd, text, strlen(text));
	if(b_write == -1) {
		std::cerr<<"Error writing file: "<<strerror(errno)<<std::endl;
		close(fd);
		return 1;
	} else if(b_write != (ssize_t)strlen(text)) {
		std::cerr<<"Partial write:  expected"<<strlen(text)<<" bytes but wrote "<<b_write<<" bytes "<<std::endl;
		close(fd);
		return 1;
	}

	if(lseek(fd, 0, SEEK_SET) == -1) {
		std::cerr<<"Error seeking file: "<<strerror(errno)<<std::endl;
		close(fd);
		return 1;
	}
	
	if(close(fd) == -1) {
                std::cerr<<"Error closing file after write: "<<strerror(errno)<<std::endl;
                return 1;
        }

	fd = open(fname, O_RDONLY);
	if(fd == -1) {
		std::cerr<<"Error opening file for reading "<<strerror(errno)<<std::endl;
		return 1;
	}

	b_read = read(fd, buffer, sizeof(buffer) -1);
	if(b_read == -1) {
		std::cerr<<"Error reading file: "<<strerror(errno)<<std::endl;
		close(fd);
		return 1;
	}

	buffer[b_read] = '\0';
	std::cout<<"File contents: "<<buffer<<std::endl;

	if(close(fd) == -1) {
		std::cerr<<"Error closing file: "<<strerror(errno)<<std::endl;
		return 1;
	}

	if(unlink(fname) == -1) {
		std::cerr<<"Error deleting file: "<<strerror(errno)<<std::endl;
		return 1;
	}

	std::cout<<"File operation completed successfully"<<std::endl;
	return 0;
}

