/*
Deletion in circulary singly linked list in c

In a circular Singly linked list, the last node of the list contains a pointer to the first node of the list.
We can have circular singly linked list as well as circular doubly linked list.
We traverse a circular singly linked list until we reach the same node where we started.
The circular singly liked list has no beginning and no ending. There is no null value present in the next part of any of the nodes. 
*/

#include<stdio.h> 
#include<stdlib.h> 
  
void create(int); 
void deletion_beginning(); 
   
   struct Node { 
   int data; 
   struct Node *next; 
  struct Node *prev;
}; 

  struct Node *head; 
  
  int main () {
  int choice,item,choice1; 
  
 do {
  printf("1.Append List\n2.Delete Node from beginning\n3.Exit\n4.Enter your choice?"); 
  scanf("%d",&choice); 
  switch(choice) {
   case 1: 
    printf("\nEnter the item\n"); 
    scanf("%d",&item); 
    create(item); 
    break; 
  case 2: 
    deletion_beginning(); 
    break; 
  case 3: 
    exit(0); 
  break; 
    default: 
  printf("\n\Enter valid choice\n"); 
} 

}  while(choice != 3); 
} 
   void create(int item){ 
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node)); 
  struct Node *temp; 
  if(ptr == NULL)  printf("\nOVERFLOW\n"); 
else {
   ptr->data=item; 
   if(head == NULL) {
  head = ptr; 
  ptr -> next = head; 
  ptr -> prev = head; 
} 
else {
  temp = head; 
  while(temp->next !=head) {
   temp = temp->next; 
} 
  temp->next = ptr; 
  ptr ->prev=temp; 
  head -> prev = ptr; 
  ptr -> next = head; 
} 
} 
   printf("\nNode Inserted\n"); 
} 
  void deletion_beginning(){
  struct Node *temp; 
  if(head == NULL) {
  printf("\n UNDERFLOW\n"); 
} 
  else if(head->next == head) {
  head = NULL; 
  free(head); 
  printf("\nNode Deleted\n"); 
} 
else {
  temp = head; 
  while(temp -> next != head) {
  temp = temp -> next; 
} 
  temp -> next = head -> next; 
  head -> next -> prev = temp; 
  free(head); 
  head = temp -> next; 
  printf("\nNode Deleted\n"); 
} 

} 
