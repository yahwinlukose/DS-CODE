#include<stdio.h>
#include<string.h>
int main(){
	char a[20][20],temp[50];
	printf("enter the number of strings:");
	int n;
	scanf("%d",&n);
	printf("enter the elements:\n");
	int i,j;
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	int low,mid,high;
	low=0;
	high=n-1;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(a[j],a[j+1])>0){
				strcpy(temp,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],temp);
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("enter an string to search:\n ");
	char s[20];
	int found=0;
	scanf("%s",s);
	while(low<=high){
		mid=(low+high)/2;
		if(strcmp(a[mid],s)==0){
			found=1;
			printf("found at %d ",mid);
			break;
		}
		else if(strcmp(a[mid],s)<0){
			low=mid+1;
		}else{
			high=mid-1;
		}
		if(found==0){
			printf("not found\n");
		}
	}

	return 0;
}
