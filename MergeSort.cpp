#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void merge(int arr[],int l,int mid,int r){
	int i=l;
	int j=mid;
	int k=0;
	int* mix = (int*) malloc((r - l) * sizeof(int));
	while(i<mid && j<r){
		if(arr[i]<arr[j]){
			mix[k]=arr[i];
			i++;
		}
		else{
			mix[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<mid){
		mix[k]=arr[i];
		i++;
		k++;
	}
	if(j<r){
		mix[k]=arr[j];
		j++;
		k++;
	}
	for(int x=0;x<(r-l);x++){
		arr[l+x]=mix[x];
	}
	free(mix);
}
void ms(int arr[],int l,int r){
	if(r-l<=1) return;
	int mid=l+(r-l)/2;
	ms(arr,l,mid);
	ms(arr,mid,r);
	merge(arr,l,mid,r);
}


int main(){
	for(int i=1;i<=20;i++){
		int n = 1000000*i; // 10^6 elements
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
		ms(arr,0,n-1);
		end=clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	//	printf("After sorting:\n");
	//	for (int i = 0; i < n; i++) {
	//        printf("%d ", arr[i]);
	//    }
	    printf("\nMergeSort took %f seconds to execute %d\n", cpu_time_used,n);
	}
	return 0;
}