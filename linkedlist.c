#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;

void Insertion_Beginning() {
	struct Node *newNode;
	newNode = NULL;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data :");
	scanf("%d", &newNode->data);
	if (head == NULL) {
		head = newNode;
		head->next = NULL;
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
    bool runOnlyOnce = false;
    void (*ptr [2])() = {Insertion_Beginning, Display};
    while(1) {
	    printf("0.Insertion_Beginning\n1.Display\n2.Exit\n");
	    printf("Enter the choice:");
	    scanf("%d", &choice);

	    if(getchar() != '\n') {
		    printf("\n***Enter valid integer***\n");
		    while ((getchar()) != '\n');
		    continue;
	    } else if (choice < 2 && choice >=0) {
		    (*ptr[choice])();
	    } else if (choice == 2) {
		    break;
	    } else {
		    printf("\n***Enter the valid choice***\n");
	    }
    }
}


