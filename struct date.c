#include<stdio.h>
#include<stdlib.h>
struct date{
	int day;
	int month;
	int year;
};
typedef struct date date;
date readdate(){
	date d;
	printf("enter the date (dd mm yyyy):");
	scanf("%d %d %d",&d.day,&d.month,&d.year);
	return d;
}
void displaydate(date d){
	printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}
int compare(date d1,date d2){
	if(d1.day==d2.day && d1.month==d2.month && d1.year==d2.year){
		printf("equal");
	}else{
		printf("not equal");
	}
}
int main(){
	date d1,d2;
	printf("enter the first date: \n");
	d1=readdate();
	printf("enter the second date: \n");
	d2=readdate();
	displaydate(d1);
	displaydate(d2);
	compare(d1,d2);
	return 0;
	
}
