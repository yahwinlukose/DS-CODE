#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char data[100];
	struct node* next;
	struct node* prev;
}node;
node* head=NULL;
void insert(char a){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=a;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL){
		head=newnode;
	}else{
		node* t;
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=newnode;
		newnode->prev=t;
	}
}
void display(){
		node* t;
		t=head;
		while(t!=NULL){
			printf("%s",t->data);
			t=t->next;
		}
}
int main(){
	char a[100];
	printf("enter  a string:");
	int i;
	scanf("%s",&a);
	for(i=0;i<strlen(a);i++){
		insert(a[i]);
	}
	display();
	return 0;
}
