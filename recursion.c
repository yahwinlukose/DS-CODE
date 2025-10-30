#include<stdio.h>
void disp(int a[],int n,int i){
	if(i==n){
		return;
	}
	disp(a,n,i+1);
	printf("%d",a[i]);
}
int main(){
	printf("enter the size of the array:\n");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("enter the elements:\n");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	disp(a,n,0);
}
