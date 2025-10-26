#include<stdio.h>
struct node{
	int data;
	struct node* next;
};

typedef struct node node;
node* head=NULL;
void insert(int a){
	node* t;
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=a;
		head->next=head;
	}else{
		t=head;
		while(t!=head){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=head;
	}
}
void delete(int a){
	node* t;
	t=head;
	if(head==NULL){
		printf("empty circular liist\n");
	}else if(head->data==a && head->next==head){    /*one element*/
		head=NULL;
	}else if(head->data==a && head->next!=head){
		for(t=head;t->next!=head;t=t->next)
		;
		t->next=head->next;
		head=head->next;
	}else{
		while(t->next->data!=a && t->next->next!=head){
			t=t->next;
		}
		if(t->next==head){
			printf("element not found");
		}else{
			
		}
	}
	
}
