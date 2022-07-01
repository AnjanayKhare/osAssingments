#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>
struct my_msg{
	long int msg_type;
	char buff[100];
}message;
int main(){
	key_t key = (key_t)1122;
	int msgid = msgget(key, 0666|IPC_CREAT);
	message.msg_type = 1;
	char ch[100] = "Anju\n";
	strcpy(message.buff, ch);
	msgsnd(msgid, &message, sizeof(message), 0);
	return 0;
}

