//Circular Queue Implementation in C using Array

#include<stdio.h>         
#include<stdlib.h>        
#define MAX 10       

int front=-1,rear=-1;       
int Circular_Q[MAX];          

void insert();
int delete();
void display();

int main(){
    int choice,nm;         
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice){
        
          case 1:
            insert();
            break;
        case 2:
            nm=delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice \n");
        }
    }
}

void insert(){
    int element;
    if((front ==0 && rear == max-1) || front == rear+1){
        printf("\nCircular Queue Is Full \n");
        return;
    }
  
    printf("\nEnter Element :");
    scanf("%d",&element);
  
    if(front==-1) front=front+1;
  
    if(rear==max-1) rear=0;
  
    else rear=rear+1;
        
    Circular_Q[rear]=element;
}

int delete(){
    int element;
    if(front==-1){
        printf("\nCircular Queue is Empty \n");
        return;
    }
  
    element=Circular_Q[front];
    if(front==max-1)    front=0;
  
    else if(front==rear){
        front=-1;
        rear=-1;
    }
  
    else front=front+1;
  
    printf("\n%d was deleted !\n",element);
    return element;
}

