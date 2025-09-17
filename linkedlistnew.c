#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

typedef struct node node;
node* head = NULL;

// Insert at end of linked list
void insert(int a) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = a;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Inserted %d into list.\n", a);
}

// Delete last node
void delete(int a) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data=a){
    	head=head->next;
	}else{
		node* t;
		for(t=head;t->next->data!=a && t->next!=NULL;t=t->next)
		;
		if(t->next==NULL){
			printf("element not found\n");
		}else{
			printf("deleted\n");
			t->next=t->next->next;
		}
	}
    

}

// Display linked list
void disp() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* t = head;
    printf("Linked List: ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

// Count nodes
int count() {
    int cnt = 0;
    node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", cnt);
    return cnt;
}

// Sort the linked list (simple bubble sort)
void sort() {
    if (head == NULL) {
        printf("List is empty, cannot sort.\n");
        return;
    }
    node* i;
    node* j;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}
void replace(int a, int b){
	if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data=a){
    	head->data=b;
	}else{
		node* t;
		int flag=0;
		for(t=head;t!=NULL;t=t->next){
			if(t->data==a){
				t->data=b;
				flag=1;
				printf("found\n");
				break;
			}
		}
		if(flag==0){
			printf("not found\n");
		}
	}
}
void search(int a){
	 if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }else if(head->data=a){
    	printf("element found");
	}else{
		node* t;
		int flag=0;
		for(t=head;t!=NULL;t=t->next){
			if(t->data==a){
				flag=1;
				printf("found\n");
				break;
			}
		}
		if(flag==0){
			printf("not found\n");
		}
	}
}
void reverse()
{
int cnt=count();
node *t1=head;
int i,j,temp;
for(i=0;i<cnt/2;i++){
    node *t2=head;
    for(j=1;j<=cnt-i-1;j++){
        t2=t2->next;
    }
    temp=t1->data;
    t1->data=t2->data;
    t2->data=temp;
    t1=t1->next;
}
}

// Display menu and get choice
int choice() {
    int ch;
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Sort\n5.Count\n6.Replace \n7.Reverse\n8.Replace\n 9.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Process user actions
void process() {
    int ch;
    for (ch = choice(); ch != 8; ch = choice()) {
        switch (ch) {
            case 1: {
                int n;
                printf("Enter the number to insert: ");
                scanf("%d", &n);
                insert(n);
                break;
            }
            case 2:
            	printf("enter a number to delete:");
            	int d;
            	scanf("%d",&d);
                delete(d);
                break;
            case 3:
                disp();
                break;
            case 4:
                sort();
                break;
            case 5:
                count();
                break;
            case 6:
            	printf("enter which value needs to be replaced:\n");
            	int val1;
            	scanf("%d",&val1);
            	printf("enter the new value:\n");
            	int val2;
            	scanf("%d",&val2);
				replace(val1,val2);
				break;
			case 7:
				reverse();
				break;
			case 8:
				printf("enter an element to search:");
				int ser;
				scanf("%d",&ser);
				search(ser);
				break;		    
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
}

int main() {            
    process();
    return 0;
}

