#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
using namespace std;

int main() {
	const char *filename = "my_file.txt";
	char buffer[100];

	//write to file
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1) {
		cerr<<"Error opening file for writing!"<<endl;
		return 1;
	}

	cout<<"Enter a string to write to the file: ";
	cin.getline(buffer, 100);

	write(fd, buffer, strlen(buffer));
	close(fd);

	//read from the file and print
	fd = open(filename, O_RDONLY);
	if(fd == -1) {
                cerr<<"Error opening file for reading!"<<endl;
                return 1;
        }

	cout<<"Contents of the fle:\n";
	int bytes_read;
	while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(fd);

	return 0;
}
