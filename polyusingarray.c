#include<stdio.h>
int main(){
	printf("enter the degree of the polynomial max(10) :\n ");
	int deg1,deg2;
	scanf("%d",&deg1);
	int poly1[11]={0},poly2[11]={0},sumpoly[11]={0};
	int i;
	printf("enter the coefficients of first polynomial:\n");
	for(i=deg1;i>=0;i--){
		printf("enter the coefficient for x^%d ",i);
		scanf("%d",&poly1[i]);
	}
	printf("the polynomial is: \n");
	for(i=deg1;i>=0;i--){
		if(poly1[i]>0 && i!=deg1){
			printf("+");
		}
		if(poly1[i]==0)continue;
		if(i==0){
			printf("%d",poly1[i]);
		}else if(i==1){
			printf("%dx",poly1[i]);
		}else{
			printf("%dx^%d",poly1[i],i);
		
		}
		
	}
	printf("\nenter the degree of the polynomial max(10) :\n ");
	scanf("%d",&deg2);
	printf("enter the coefficients of  polynomial 2:\n");
	for(i=deg2;i>=0;i--){
		printf("enter the coefficient for x^%d ",i);
		scanf("%d",&poly2[i]);
	}
	printf("the polynomial is: \n");
	for(i=deg2;i>=0;i--){
		if(poly2[i]>0 && i!=deg2){
			printf("+");
		}
		if(poly2[i]==0)continue;
		if(i==0){
			printf("%d",poly2[i]);
		}else if(i==1){
			printf("%dx",poly2[i]);
		}else{
			printf("%dx^%d",poly2[i],i);
		
		}
		
	}
	int maxdeg=(deg1>deg2)?deg1:deg2;
	for(i=maxdeg;i>=0;i--){
		sumpoly[i]=poly1[i]+poly2[i];
	}
	printf("Polynomial after sum: \n");
	for(i=maxdeg;i>=0;i--){
		if(sumpoly[i]==0)continue;
		if(sumpoly[i]>0 && i!=maxdeg)printf("+");
		if(i==0){
			printf("%d",sumpoly[i]);
		}else if(i==1){
			printf("%dx",sumpoly[i]);
		}else{
			printf("%dx^%d",sumpoly[i],i);
		}
	}
	return 0;
}
