#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
typedef struct node queue;

queue* front=NULL;
queue* rear=NULL;
void insert(int a){
	if(rear==NULL){
		rear=(queue*)malloc(sizeof(queue));
		front=rear;
		rear->data=a;
		rear->next=NULL;
	}else{
		queue* t=rear;
		t=(queue*)malloc(sizeof(queue));
		t->data=a;
		t->next=NULL;
		rear->next=t;
		rear=t;
	}
}
void dequeue(){
	if(front==NULL){
		printf("empty\n");
	}else if(front==rear){
		front=rear=NULL;
	}else{
		front=front->next;
	}
}
void display(){
	queue* i;
	for(i=front;i!=NULL;i=i->next){
		printf("%d ",i->data);
	}
}
int main(){
	insert(210);
	insert(2);
	insert(30);
	insert(40);
	display();
	printf("\n");
	dequeue();
	display();
	printf("\n");
	return 0;
}
