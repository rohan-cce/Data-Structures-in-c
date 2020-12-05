/*
                             Queue implementation using linked list

        A Queue is a linear structure which follows a particular order in which the 
        operations are performed. The order is First In First Out (FIFO).
        A good example of a queue is any queue of consumers for a resource where the consumer that
        came first is served first. 
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(int element);
void delete();
void display();

int main(){
   int choice,element;
   while(1){
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice : ");
      scanf("%d",&choice);
      switch(choice){
	     case 1: 
          printf("Enter the value to be insert: ");
		      scanf("%d", &element);
		      insert(element);
		      break;
	     case 2:
          delete();
          break;
	     case 3:
          display();
          break;
	     case 4:
          exit(0);
	     default:
          printf("\nInvalid Choice\n");
      }
   }
}
void insert(int element){
   struct Node *ptr;
   ptr = (struct Node*)malloc(sizeof(struct Node));
   ptr->data = element;
   if(front == NULL)
      front = rear = ptr;
   else{
      rear -> next =ptr;
      rear = ptr;
   }ptr->next = NULL;
   printf("Successfully Inserted");
}
void delete(){
   if(front == NULL)
      printf("\nQueue is Empty\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void display(){
   if(front == NULL)
      printf("\nQueue is Empty \n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	      printf("%d--->",temp->data);
	      temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
