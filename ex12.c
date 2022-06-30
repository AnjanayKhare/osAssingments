#include <stdio.h>
#include <unistd.h>

int main(){
	int pid, n, i, ans = 0;
	int arr[] = {1, 2, 7, 5, 4, 32, 89};
	n = 7;
	pid = fork();
	if(pid > 0){
		for (i=0;i<n;i+=2){
			ans+=arr[i];
		}
		printf("Parent Process, Ans = %d\n", ans);
	}else{
		for (i=1;i<n;i+=2){
			ans+=arr[i];
		}
		printf("Child Process, Ans = %d\n", ans);
	}
}
