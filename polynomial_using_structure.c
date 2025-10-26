#include<stdio.h>
#include<stdlib.h>
struct term{
	int coeff;
	int exp;
};
typedef struct term term;
int main(){
	term p[5];
	int i,n;
	printf("enter the no of terms:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter coefficient and exponent:\n");
		scanf("%d%d",&p[i].coeff,&p[i].exp);
	}
	for(i=0;i<n-1;i++){
		printf("%dx^%d",p[i].coeff,p[i].exp);
		printf("%s",p[i+1].coeff>0?"+":"-");
		
	}
	if(p[i].exp==0){
		printf("%d",p[i].coeff);
	}
	
    
    return 0;
}

