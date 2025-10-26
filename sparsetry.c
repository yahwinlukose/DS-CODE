#include<stdio.h>
int main(){
	int rows,cols;
	int matrix[10][10];
	printf("enter the number of rows and columns:\n");
	scanf("%d\n%d",&rows,&cols);
	printf("enter the matrix elements:");
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	int count=0;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(matrix[i][j]!=0){
				count++;
			}
		}
	}
	int sparse[10][3];
	int k=0;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(matrix[i][j]!=0){
				sparse[k][0]=i;
				sparse[k][1]=j;
				sparse[k][2]=matrix[i][j];
				k++;
			}
		}
	}
	printf("\nSparse Matrix Representation (row, col, value):\n");
	for(i=0;i<k;i++){
		printf("%d\t%d\t%d\t\n",sparse[i][0],sparse[i][1],sparse[i][2]);
	}
	return 0;
}
