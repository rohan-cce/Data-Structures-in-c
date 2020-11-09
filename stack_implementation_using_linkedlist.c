#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;
struct Node* temp;
int count = 0;

void display()
void push(int ele)
void pop()

int main()
{
	int choice;
	int el;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\nChoice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nElement to be inserted: ");
				scanf("%d", &el);
				push(el);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				printf("\nInvalid Input!\n");			
		}
	}
	return 0;
}
