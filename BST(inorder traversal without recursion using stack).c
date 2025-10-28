#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}tree;
tree* createNode(int a){
	tree* newNode=(tree*)malloc(sizeof(tree));
	newNode->data=a;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
tree* insert(tree* root,int a){
	if(root==NULL)
		return createNode(a);
	if(root->data<a)
		root->right=insert(root->right,a);
	else if(root->data>a)
		root->left=insert(root->left,a);
	return root;	
}
void inordertraversal(tree* root){
	tree* stack[100];
	int top=-1;
	tree* current=root;
	while(current!=NULL || top!=-1){
		while(current!=NULL){
			stack[++top]=current;
			current=current->left;
		}
		current=stack[top--];
		printf("%d ",current->data);
		current=current->right;
	}
}
int main(){
	tree* root=NULL;
	printf("enter the number of nodes:\n");
	int n;
	scanf("%d",&n);
	int i;
	printf("enter the elements:\n");
	int a;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a);
	}
	inordertraversal(root);
	return 0;
}
