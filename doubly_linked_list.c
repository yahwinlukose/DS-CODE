#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node node;
node* head=NULL;
void insert(int a){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->data=a;
		head->next=NULL;
		head->prev=NULL;
	}else{
		node* t;
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
		t->next->prev=t;
		
	}
}
void delete_val(int a){
	if(head==NULL){
		printf("empty linked list\n");
	}else if(head->data==a){
		head=head->next;
	}else{
		node* t;
		t=head;
		while(t!=NULL && t->data!=a){
			t=t->next;
		}
		if(t==NULL){
			printf("element not found\n");
		}else{
			t->prev->next=t->next;
			if(t->next!=NULL){
					t->next->prev=t->prev;
			}
		
		}
	}
}
