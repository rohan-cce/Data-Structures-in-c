// Stack implementation in C using Array.

#include<stdio.h>
#include<stdlib.h>  
#define max 10      

int stack[max],top=-1;         

void push();
int pop();
void disp();

int main(){
    int choice,r;        
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display the Stack\n4.EXIT");
        printf("\n\nEnter Your Choice ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            push();
            break;
        case 2:
            r=pop();
            break;
        case 3:
            disp();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice\n");
        }
    }
}

void push(){
    int number;
    if(top==max-1){
        printf("\nStack is Full \n");
        return;
    }else{
        printf("\nEnter a number for Insert : ");
        scanf("%d",&number);
        top++;
        stack[top]=number;
    }
}

int pop(){
    int del;
    if(top==-1){
        printf("\nStack is Empty \n");
        return;
    } else {
        del=stack[top];
        printf("\n%d was Deleted !\n",del);
        top--;
        return del;
    }

}
void disp(){
    int i;
    if(top==-1){
        printf("\nStack Empty!\n");
        return;
    } else {
        printf("\n");
        for(i=top;i>=0;i--)
            printf("\n%d",stack[i]);
        printf("\n");
    }
}
