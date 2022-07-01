#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <string.h>

struct my_msg{
	long int msg_type;
	char text[100];
}message;

int main(){
	key_t key = (key_t)1122;
	message.msg_type = 1;
	int msgid = msgget(key, 0666|IPC_CREAT);
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	printf("%s", message.text);
	return 0;
}
