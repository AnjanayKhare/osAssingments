#include <stdio.h>
#include <unistd.h>

void printarr(int arr[], int n){
	int i;
	for (i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
	int pid;
	int arr[7] = {12, 11, 9, 5, 10, 15, 80};
	int n = 7;
	pid = fork();
	if (pid > 0){
		insertionSort(arr, n);
		printf("Parent Process\n");
		printarr(arr, n);
	}else{
		selectionSort(arr, n);
		printf("Child Process\n");
		printarr(arr, n);
	}
}
