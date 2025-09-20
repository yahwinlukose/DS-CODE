#include<stdio.h>
void main(){
	char a[10];
	printf("enter a string :");
	scanf("%s",a);
	int i=0;
	int len=0;
	while(a[i]!='\0'){
		len++;
		i++;
	}
	for(i=0;i<len/2;i++){
		char temp=a[i];
		a[i]=a[len-1-i];
		a[len-1-i]=temp;
	}
	
	printf("the reverse of the string is : %s\n",a);
}
