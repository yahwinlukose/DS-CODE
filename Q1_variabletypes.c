#include<stdio.h>
int a=50; //global variable
int counter(){
	int count=0;
	count++;
	printf("%d\n",count);
}
void main(){
	int b=40;//local variable
	register int c=60;//value is stored in register and not in memory
	printf("%d\n",a); //displays a (global variable)
	printf("%d\n",b); //displays b (local variable)
	printf("%d\n",c); //displays c (register variable) 
	counter(); //displays 1
	counter(); //displays 2
	counter(); //displays 3
	
	
}
