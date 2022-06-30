#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main(){
	int shmid;
	key_t key;
	key = ftok("shmfile", 65);
	shmid = shmget(key, 1024, 0666|IPC_CREAT);
	void *sharedMem;
	sharedMem= shmat(shmid, NULL, 0);
	char msg[100] = "Anju";
	strcpy(sharedMem, msg);
	printf("Prodcess 1 data written %s\n", (char *)sharedMem);
	return 0;
}
