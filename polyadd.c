#include<stdio.h>
struct term{
	int coeff;
	int exp;
};
typedef struct term term;
int main(){
	term poly1[20],poly2[20],result[20];
	int deg1,deg2,maxdeg;
	printf("enter the degree of the poly:\n");
	scanf("%d",&deg1);
	printf("enter the degree of the second poly:\n");
	scanf("%d",&deg2);
	printf("enter the coefficients of the first poly:\n");
	int i;
	for(i=0;i<=deg1;i++){
		printf("enter the coefficient of x^%d ",i);
		scanf("%d",&poly1[i].coeff);
		poly1[i].exp=i;
	}
	printf("enter the coefficients of the second poly:\n");
	for(i=0;i<=deg2;i++){
		printf("enter the coefficient of x^%d ",i);
		scanf("%d",&poly2[i].coeff);
		poly2[i].exp=i;
	}

	maxdeg=(deg1>deg2)?deg1:deg2;
	for(i=0;i<=maxdeg;i++){
		int c1=(i<=deg1)?poly1[i].coeff:0;
		int c2=(i<=deg2)?poly2[i].coeff:0;
		result[i].coeff=c1+c2;
		result[i].exp=i;
	}
	for(i=maxdeg;i>=0;i--){
		if(result[i].coeff!=0){
			if(result[i].exp==0){
				printf("%d ",result[i].coeff);
			}else if(result[i].exp==1){
				printf("%dx ",result[i].coeff);
			}else{
				printf("%dx^%d ",result[i].coeff,result[i].exp);
			}
			if(i!=0){
				printf("+");
			}
		}
	}
	
	printf("\n");
	return 0;
}

