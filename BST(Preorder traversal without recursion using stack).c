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
void preordertraversalwithoutrecursion(tree* root){
	if(root==NULL)
		return;
	tree* stack[100];
	int top=-1;
	stack[++top]=root;
	while(top!=-1){
		tree* current=stack[top--];
		printf("%d ",current->data);
		if(current->right)
			stack[++top]=current->right;
		if(current->left)
			stack[++top]=current->left;
			
	}
	
}
int main(){
	tree* root=NULL;
	printf("enter the number of nodes\n");
	int n;
	scanf("%d",&n);
	printf("enter the elements\n");
	int i;
	int a[100];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		root=insert(root,a[i]);
	}
	preordertraversalwithoutrecursion(root);
	return 0;
	
}
