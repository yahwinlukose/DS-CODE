#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	char data[100];
	struct node* next;
};
typedef struct node node;
node* head=NULL;
void insert(char* a){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		strcpy(head->data,a);
		head->next=NULL;
	}else{
		node* t;
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		strcpy(t->next->data,a);
		t->next->next=NULL;
	}
}
void delete_val(char* a){
	node* t;
	t=head;
	if(head==NULL){
		printf("empty\n");	
	}else if(strcmp(head->data,a)==0){
		head=head->next;
	}else{
		while(t->next!=NULL && strcmp(t->next->data,a)!=0){
			t=t->next;
		}
		if(t->next==NULL){
			printf("not found\n");
		}else{
			t->next=t->next->next;
		}
	}
}
void disp(){
	node* t;
	t=head;
	while(t!=NULL){
		printf("%s \t",t->data);
		t=t->next;
	}
}
int main(){
	insert("yahwin");
	insert("godwin");
	insert("vava");
	delete_val("yahwin");
	
	disp();
}

