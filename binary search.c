#include<stdio.h>
int search(int a[],int key,int n){
	int high,low;
	low=0;
	high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)	
			low=mid+1;
		else
			high=mid-1;	
	}
	return -1;
}
int main(){
	printf("enter the size of the array:\n");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of the array: \n");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter an element to search:\n");
	int key;
	scanf("%d",&key);
	int pos=search(a,key,n);
	if(pos!=-1){
		printf("elemment found at %d",pos+1);
	}else{
		printf("element not found");
	}
	return 0;
}
