#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct node *next;
};

struct Node *head = NULL;

void Insertion_Beginning(){
	struct Node *newNode;
	newNode = NULL;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data :");
	scanf("%d", &newNode->data);
	if(head == NULL) {
		head = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
	printf("\nNode inserted\n");
}

void Display(){
	int count = 0;
	struct Node *newNode;
	printf("Available data :\n");
	newNode = head;
	while(newNode != NULL){
		printf("%d\n", newNode->data);
		count ++;
		newNode = newNode->next;
	}
	printf("\nTotal nodes:%d\n", count);
}

int main(){
    int choice;
    void (*ptr [3])()={Insertion_Beginning, Display};
    while(1)
    {
	    printf("\n0.Insertion_Beginning\n1.Display\n");
	    printf("Enter the choice:");
	    scanf("%d", &choice);
	    if(choice < 2) {
		    (*ptr[choice])();
	    } else {
		    printf("\n******Enter the valid choice******\n");
	    }
    }
}
