#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree* right;
	struct tree* left;
};
typedef struct tree tree;
tree* root=NULL;
void insert(int a){
	tree *x,*p;
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->data=a;
		root->left=NULL;
		root->right=NULL;
	}else{
		x=root;
		while(x!=NULL){
			p=x;
			if(x->data<a)
				x=x->right;
			else
				x=x->left;	
		}
		if(p->data<a){
			p->right=(tree*)malloc(sizeof(tree));
			p->right->data=a;
			p->right->left=NULL;
			p->right->right=NULL;
		}else{
			p->left=(tree*)malloc(sizeof(tree));
			p->left->data=a;
			p->left->left=NULL;
			p->left->right=NULL;
		}
	}
}
void inorder(tree* r){
	tree* stack[50];
	int top=-1;
	tree* curr=r;
	while(curr!=NULL || top!=-1){
		while(curr!=NULL){
			stack[++top]=curr;
			curr=curr->left;
		}
		curr=stack[top--];
		printf("%d",curr->data);
		curr=curr->right;
	}
}
void preorder(tree* r){
	if(root==NULL)
		return;
	tree* stack[50];
	int top=-1;
	stack[++top]=root;
	while(top!=-1){
		tree* curr=stack[top--];
		printf("%d",curr->data);
		if(curr->left)
			stack[++top]=curr->left;
		if(curr->right)
			stack[++top]=curr->right;	
	}	
}
int main(){
	insert(10);
	insert(20);
	insert(30);
	inorder(root);
}


