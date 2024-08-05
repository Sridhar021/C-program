#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<sys/stat.h>
#include<cstdio>

void createFile(const char* filename) {
	int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("Error opening file");
		return;
	}
	std::cout<<"File created successfully.\n";
	close(fd);
}

void writeFile(const char* filename, const char* content) {
	int fd = open(filename, O_WRONLY);
	if(fd == -1) {
                perror("Error opening file for writting ");
                return;
        }
	ssize_t byteswrite = write(fd, content, strlen(content));
	if(byteswrite == -1) {
                perror("Error writting to file");
        } else {
		std::cout<<"Written to file successfully.\n";
	}
	close(fd);
}

void readFile(const char* filename) {
	int fd = open(filename, O_RDONLY);
	if(fd == -1) {
                perror("Error opening file for reading");
                return;
        }
	char buffer[1024];
	ssize_t bytesread;
	while((bytesread = read(fd, buffer, sizeof(buffer) -1)) > 0) {
		buffer[bytesread] = '\0';
		std::cout<<buffer;
	}
	if(bytesread == -1) {
                perror("Error reading from file");
                
        }
	std::cout<<"\n";
	close(fd);
}

void appendFile(const char* filename, const char* content) {
        int fd = open(filename, O_WRONLY | O_APPEND);
        if(fd == -1) {
                perror("Error opening file for appending ");
                return;
        }
        ssize_t byteswrite = write(fd, content, strlen(content));
        if(byteswrite == -1) {
                perror("Error appending to file");
        } else {
                std::cout<<"Append to file successfully.\n";
        }
        close(fd);
}

void deleteFile(const char* filename) {
	if(unlink(filename) == -1) {
		perror("Error deleting file");
	}
	else {
		std::cout<<"File deleted successfully.\n";
	}
}

int main() {
	const char* filename = "example.txt";
	const char* content = "Hi my name is Sridhar.M";
	const char* extracontent = "I am training";

	createFile(filename);
	writeFile(filename, content);

	std::cout<<"Reading file after writing\n";
	readFile(filename);
	appendFile(filename, extracontent);
	
	std::cout<<"Reading file after appending\n";
	readFile(filename);
	deleteFile(filename);

	return 0;
}

