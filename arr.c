/*Program to display the elements of an array using recursion
@Jubin Joy 35 23/07/2025 */

#include<stdio.h>
void disp(int a[],int n) //function to display all the elements in the array using recursion
{
	if(n!=0)
		disp(a,n-1);
	printf("%d ",a[n]);
	
}
void read(int a[],int n) //function to insert elements into the array
{
	int i;
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
int main()
{
	int a[10],n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	read(a,n);
	printf("The elements of the array are:");
	disp(a,n-1);
	return 0;
}
