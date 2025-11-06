#include<stdio.h>
int main(){
	int n;
	printf("enter the number of vertices:\n");
	scanf("%d",&n);
	int adj[n][n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			adj[i][j]=0;
		}
	}
	printf("enter the number of edges:\n");
	int e;
	scanf("%d",&e);
	printf("enter the edges:\n");
	for(i=0;i<e;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u][v]=1;
		adj[v][u]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d",adj[i][j]);
		}
	}
	return 0;
}
