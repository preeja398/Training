#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
struct Node* next;
};
void insert(struct Node** head_ref, int new_data)
{
struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
new_node->data = new_data;
  new_node->next = (*head_ref);
(*head_ref) = new_node;
}
void printList(struct Node* head)
{
struct Node* temp = head;
  while (temp != NULL)
{   printf("%d  ", temp->data);
  temp = temp->next;
}
}
int main()
{
struct Node* head = NULL;
insert(&head, 2);
insert(&head, 4);
insert(&head, 6);
insert(&head, 8);
printList(head);
return 0;
}
