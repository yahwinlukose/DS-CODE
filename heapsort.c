struct poly{
	int coeff;
	int exp;
};
int main(){
	struct poly poly1[10],poly2[10],result[20];
	int deg1,deg2;
	int i,j;
	printf("enter the degree of first poly:\n");
	scanf("%d",&deg1);
	printf("enter the coefficients from x^0 to x^%d\n",deg1);
	for(i=0;i<=deg1;i++){
		printf("enter coefficient of x^%d\n",i);
		scanf("%d",&poly1[i].coeff);
		poly1[i].exp=i;
	}

	printf("enter the degree of second poly:\n");
	scanf("%d",&deg2);
	printf("enter the coefficients from x^0 to x^%d\n",deg2);
	for(i=0;i<=deg2;i++){
		printf("enter coefficient of x^%d\n",i);
		scanf("%d",&poly2[i].coeff);
		poly2[i].exp=i;
	}

int maxdeg=deg1+deg2;
for(i=0;i<=maxdeg;i++){
	result[i].coeff=0;
	result[i].exp=i;
}
int k;
printf("the result after multiplication is:\n");
for(i=0;i<=deg1;i++){
	for(j=0;j<=deg2;j++){
		k=poly1[i].exp+poly2[j].exp;
		result[k].coeff=poly1[i].coeff*poly2[j].coeff;
	}
}
printf("the result after multiplication is:\n");
for(i=maxdeg;i>=0;i--){
	if(i!=maxdeg && result[i].coeff>0){
		printf("+");
	}
	printf("%dx^%d",result[i].coeff,result[i].exp);
}
}
