#include<stdio.h>
#include<stdlib.h>

struct Stack{
	int data;
	struct Stack* next;
};

struct Stack* top = NULL;
struct Stack* temp;
int count = 0;

void display()
void push(int item)
void pop()

int main(){
	int choice;
	int element;
	while(1){
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit : ");
		printf("Enter Your Choice\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter Element to be inserted : ");
				scanf("%d", &element);
				push(element);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("\nInvalid Input\n");			
		}
	} return 0;
}
void display(){
	temp = top;
	if(count == 0){
		printf("\nStack is Empty \n");
		return;
	} else {
		printf("\nThere are  %d items:-\n", count);
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		} printf("\n");
	}
}

void push(int item){
	if(top == NULL){
		top = (struct Stack*) malloc(sizeof(struct Stack*));
		top->data = item;
		top->next = NULL;
	} else {
		temp = (struct Stack*) malloc(sizeof(struct Stack*));
		temp->next = top;
		temp->data = item;
		top = temp;
	} count++;
	
}

void pop(){
	temp = top;
	if(top == NULL){
		printf("\nStack is empty!\n");
		exit(1);
	}else{
		temp = temp->next;
	}
	printf("\n%d Removed ", top->data);
	free(top);
	top = temp;
	count--;
	
}

