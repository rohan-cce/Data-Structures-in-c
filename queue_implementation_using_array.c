#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 50

void insert();
void delete();
void display();

int queue_array[MAX_ELEMENT];
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
      if (rear == MAX - 1)       printf("Queue Overflow \n");
      else{
        if (front == - 1)  front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &element);
        rear = rear + 1;
        queue_array[rear] = element;
      }
} 
 

void delete(){
      if (front == - 1 || front > rear){
            printf("Queue Underflow \n");
            return ;
      }

    else{
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

 

void display(){
    int i;
    if (front == - 1)   printf("Queue is empty \n");
    else{
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
              printf("%d ", queue_array[i]);
         printf("\n");
  }
}
