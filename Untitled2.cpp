#include<stdio.h>
#include<stdlib.h>
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
		head->next=NULL;
	}else{
		t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=NULL;
	}
}
void deletee(int a){
	node* t;
	t=head;
	if(head==NULL){
		printf("empty\n");
		return;
	}else if(head->data==a){
		head=head->next;
		
	}else{
		while(t->next!=NULL && t->next->data!=a){
			t=t->next;
		}
		if(t->next==NULL){
			printf("element not found\n");
		}else{
			t->next=t->next->next;
			
			
		}
	}
}
void disp(){
	node* t;
	t=head;
	for(t=head;t!=NULL;t=t->next){
		printf("%d -> ",t->data);
	}
}
void sort(){
	int temp;
	node* i;
	node* j;
	for(i=head;i!=NULL;i=i->next){
		for(j=head;j->next!=NULL;j=j->next){
			if(j->data>j->next->data){
				temp=j->data;
				j->data=j->next->data;
				j->next->data=temp;
			}
		}
	}
	printf("sorted successfully\n");
}
void find(int a){
	node* t;
	t=head;
	while(t->next!=NULL){
		t=t->next;
	}
	if(t->data==a){
			printf("found at %d",t);
		}else{
			printf("not found\n");
			}
}
void findandreplace(int b){
	node* t;
	t=head;
	while(t!=NULL){
		if(t==NULL){
			printf("ELEMENT NOT FOUND\n");
		}else{
			t->data=b;
		}
	}
}
int menu(){
	int ch;
	printf("1.Insert\n 2.Delete\n 3.Exit\n");
	scanf("%d",&ch);
	return ch;
}
int process(){
	int ch;
	for(ch=menu();ch!=3;ch=menu()){
		switch(ch){
			case 1:
				int a;
				printf("enter an element to insert:\n");
				scanf("%d",&a);
				insert(a);
				break;
			case 2:
				int b;
				printf("enter an element to delete:\n");
				scanf("%d",&b);
				deletee(b);
				break;
			case 3:
				disp();
				break;	
			case 4:
				sort();
				break;
			case 4:
					
			default:
				printf("entered the wrong choice\n");	
		}
	}
}
