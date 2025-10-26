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
		head->next=head;
		head->prev=head;
	}else{
		node* t;
		t=head;
		while(t->next!=head){
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=a;
		t->next->next=head;
		t->next->prev=t;
		head->prev=t->next;
		
	}
}
void delete_val(int a){
	if(head==NULL){
		printf("empty linked list\n");
	}else if(head->next==head && head->data==a){
			head=NULL;
	}else if(head->data==a){
		node* t;
		t=head;
		while(t->next!=head){
			t=t->next;
		}
		head=head->next;
		t->next=head;
		head->prev=t;
	}else{
		node* t;
		t=head->next;
		while(t!=head && t->data!=a){
			t=t->next;
		}
		if(t==head){
			printf("element not found\n");
		}else{
			t->prev->next=t->next;
			if(t->next!=head){
					t->next->prev=t->prev;
			}
		
		}
	}
}
void sort(){
	if(head==NULL || head->next==head){
		printf("nothing to sort\n");
		return;
	}
	node* i;
	node* j;
	int temp;
	for(i=head;i->next!=head;i=i->next){
		for(j=i->next;j!=head;j=j->next){
			if(i->data >j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
				
			}
		}
	}
	printf("sorted\n");
}
void disp(){
	node* t;
	t=head;
	do{
		printf("%d\t",t->data);
		t=t->next;
	}while(t!=head);
}
int main(){
	insert(10);
	insert(200);
	insert(20);
	sort();
	delete_val(200);
	disp();
}
