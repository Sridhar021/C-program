#include<iostream>
#include<unistd.h>
#include<cstring>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define M_SIZE 128

struct message_buffer{
	long message_type;
	char message_text[M_SIZE];
};

int main() {
	key_t key;
	int msgid;
	pid_t pid;
	
	key = ftok("progfile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);

	if(msgid == -1) {
		perror("message");
		return 1;
	}

	pid = fork();
	if(pid == -1) {
		perror("fork");
		return 1;
	}

	if(pid == 0) {
		message_buffer msg;
		
		if(msgrcv(msgid, &msg, sizeof(msg.message_text), 1, 0) == -1) {
			perror("msgrcv");
		}
		std::cout<<"Child received: "<<msg.message_text<<std::endl;
		if(msgctl(msgid, IPC_RMID, NULL) == -1) {
			perror("msgctl");
			return 1;
		}
	}
	else {
		message_buffer msg;
		msg.message_type = 1;
		const char *message= "Hello from parent";
		strncpy(msg.message_text, message, M_SIZE);
		if(msgsnd(msgid, &msg, sizeof(msg.message_text), 0) == -1) {
			perror("msgsnd");
			return 1;
		}
		wait(NULL);
	}
	return 0;
}

