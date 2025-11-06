#include<stdio.h>
#include<string.h>
int main(){
	char s[10];
	
	printf("enter the string:\n");
	scanf("%s",s);
	int len=strlen(s);
	int i,j;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			char temp=s[j];
			s[j]=s[j+1];
			s[j+1]=temp;
		}
	
	}
	printf("%s",s);
	
	return 0;
}
