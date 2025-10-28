#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert(int a){
	if(rear==MAX-1){
		printf("already full");
	}else{
		if(front==-1){
			front=0;
		}
		queue[++rear]=a;
	}
}
void delete_val(){
	if(front==-1){
		printf("empty");
	}else{
		int del_val=queue[front];
		if(front==rear)
			front=rear=-1;
		else	
			front++;
		printf("deleted value is %d :",del_val);
	}
}
void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
}
int main(){
	insert(10);
	insert(20);
	insert(30);
	display();
	printf("\n");
	delete_val();
	printf("\n");
	display();
	return 0;
}
