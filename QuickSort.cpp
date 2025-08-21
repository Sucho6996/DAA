#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partition(int arr[],int l,int r){
	int pivot=arr[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,r);
	return i+1;
}
void qs(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int pi=partition(arr,l,r);
	qs(arr,l,pi-1);
	qs(arr,pi+1,r);
}
int main(){
	int n = 1000000-10000; // 10^6 elements
    int *arr = (int*) malloc(n * sizeof(int));
    srand(time(NULL));
    // Generate random array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
	clock_t start, end;
    double cpu_time_used;
//	printf("Before sorting:\n");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
    printf("\n");
    start=clock();
	qs(arr,0,n-1);
	end=clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
//	printf("After sorting:\n");
//	for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
    printf("\nQuickSort took %f seconds to execute %d\n", cpu_time_used,n);
	return 0;
}