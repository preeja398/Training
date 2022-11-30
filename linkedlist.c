#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *head=NULL;


void insertion_beginning()
{
struct node *newNode;
newNode =NULL;
newNode=(struct node*)malloc(sizeof(struct node));
printf("enter data :");
scanf("%d",&newNode->data);
if(head==NULL)
{
head=newNode;
}
else
{
newNode->next=head;
head=newNode;
}
printf("\nNode inserted\n");
}

void display()
{
int count=0;
struct node *newNode;
printf("Available data:\n");
newNode=head;
while(newNode!=NULL)
{
printf("%d\n",newNode->data);
count++;
newNode=newNode->next;
}
printf("\nTotal nodes:%d\n",count);
}

int main()
{
int choice;
 void (*ptr [3])()={ insertion_beginning, display,exit};
while(1)
{
printf("\n0. insertion_beginning\n1. display\n2.Exit\n");
printf("Enter the choice:");
scanf("%d",&choice);
if(choice <3)
(*ptr[choice])();
else
printf("\n******Enter the valid choice******\n");
}
}
