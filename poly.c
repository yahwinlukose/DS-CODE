#include<stdio.h>
#include<stdlib.h>
struct term{
	int coeff;
	int exp;
};
int main(){
	struct term poly[20];
	int n,i;
	printf("enter the number of terms:\n");
	scanf("%d",&n);
	printf("enter the terms:(coefficients then exponents)\n");
	for(i=0;i<n;i++){
		printf("enter term %d",i+1);
		scanf("%d%d",&poly[i].coeff,&poly[i].exp);
	}
	printf("the polynomail is:\n");
	for(i=0;i<n;i++){
		printf("%dx^%d",poly[i].coeff,poly[i].exp);
		if(i!=n-1){
			printf("+");
		}
	}
	printf("\n");
return 0;
}

