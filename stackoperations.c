#include <stdio.h>
#define MAX 10

char stack[MAX];
int top = -1;
char str2[10];
char a[20];

// Function to push characters into stack
void insert(char a[]) {
    int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (top == MAX - 1) {
            printf("Stack overflow at character %c\n", a[i]);
            return;
        } else {
            stack[++top] = a[i];
        }
    }
}

// Function to print stack content
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
    	int i;
        printf("Stack contents:\n");
        for (i = 0; i <= top; i++) {
            printf("%c ", stack[i]);
        }
        printf("\n");
    }
}
void reverse(){
	int i;
	printf("reversed string\n");
	for(i=top;i>=0;i--){
		printf("%c ",stack[i]);
	}
	printf("\n");
}

void concat(){
	printf("enter anothers string:\n");
	
	scanf("%9s",str2);
	int i;
	for(i=0;str2[i]!='\0';i++){
		if(top==MAX-1){
			printf("stack overflow\n");
			return;
		}else{
			stack[++top]=str2[i];
		}
	}
}
void compare(){
	int i;
	int count=0;
	for(i=0;a[i]!='\0' && str2[i]!='\0';i++){
		if(a[i]!='\0' && str2[i]!='\0' && a[i]==str2[i]){
			count++;
		}
	}
	if(count==i){
		printf("The two strings are equal\n");
	}else{
		printf("not equal\n");
	}
}
int main() {
    
    printf("Enter a string: ");
    scanf("%19s", a); // limit input to avoid overflow

    insert(a);
    display(); // show stack content
    reverse();
    display();
    concat();
    compare();

    return 0;
}

