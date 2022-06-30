#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main(){
	key_t key = ftok("shmfile", 65);
	int shmid = shmget(key, 1024, 0666);
	void *shrdmem = shmat(shmid, NULL, 0);
	printf("You Wrote %s\n", (char *)shrdmem);
}
