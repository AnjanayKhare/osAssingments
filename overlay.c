#include <stdio.h>
#include <unistd.h>


int main(){
	printf("This Process\n");
	char *args[] = {"./child", NULL};
	execvp(args[0], args);
	return 0;
}
