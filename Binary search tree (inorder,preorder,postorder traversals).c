#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}tree;
tree* root=NULL;
void insert(int a){
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->data=a;
		root->left=NULL;
		root->right=NULL;
	}else{
		tree *p,*x;
		x=root;
		while(x!=NULL){
			p=x;
			if(x->data<a){
				x=x->right;
			}else{
				x=x->left;
			}
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
void inorder(tree* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
	
}
void postorder(tree* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}

}
void preorder(tree* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}

}
int main(){
	insert(10);
	insert(50);
	insert(30);
	insert(40);
	inorder(root);
	printf("\n");

	preorder(root);
	printf("\n");

	postorder(root);
	printf("\n");

	return 0;
}
