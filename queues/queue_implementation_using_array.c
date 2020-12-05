/*
        Queue implementation using array
        
        A Queue is a linear structure which follows a particular order in which the 
        operations are performed. The order is First In First Out (FIFO).
        A good example of a queue is any queue of consumers for a resource where the consumer that
        came first is served first. 
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 100

void insert();
void delete();
void display();

int queue[MAX_ELEMENTS];
int rear = - 1,front = - 1;

int main(){
    int choice;
    while (1){
        printf("1.Insert element to queue \n2.Delete element from queue \n3.Display all elements of queue \n4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice){
           case 1:
              insert();
               break;
           case 2:
                delete();
                break;
           case 3:
                display();
                break;
           case 4:
                exit(1);
           default:
                printf("Wrong choice \n");
        }
    }
} 
 

void insert(){
      int element;
      if (rear == MAX_ELEMENTS - 1)       printf("Queue Overflow \n");
      else{
        if (front == - 1)  front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &element);
        rear = rear + 1;
        queue[rear] = element;
        printf("Inserted Successfully");
      }
} 
 

void delete(){
      if (front == - 1 || front > rear){
            printf("Queue Underflow \n");
            return ;
      }else{
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

 

void display(){
    int i;
    if (front == - 1)   printf("Queue is empty \n");
    else{
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
              printf("%d ", queue[i]);
         printf("\n");
  }
}
