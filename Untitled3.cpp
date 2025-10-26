#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char item[200];
	int quantity;
	float price;
	
	struct node* next;
};
typedef struct node node;
node* head=NULL;
void insert(char* item,int quantity,float price){
	node* newNode=(node*)malloc(sizeof(node));
	strcpy(newNode->item,item);
	newNode->quantity=quantity;
	newNode->price=price;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
	}else{
		node* t;
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=newNode;
	
	}
}
