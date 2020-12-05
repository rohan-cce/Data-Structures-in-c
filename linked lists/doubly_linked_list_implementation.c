/*
Doubly linked list implementation in c

Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous 
as well as the next node in the sequence.

                                                            Doubly Linked list
                +----------------------------------------------------------------------------------+--------------------+
                |                                   Time complexity                                |   Space Complexity |
                +----------------------------------------+-----------------------------------------+--------------------+
                |               Average case             |                   Worst Case            |     Worst Case     |
                +--------+--------+-----------+----------+---------+--------+-----------+----------+--------------------+
                | Access | Search | Insertion | Deletion |  Access | Search | Insertion | Deletion |                    |
                +--------+--------+-----------+----------+---------+--------+-----------+----------+--------------------+
                |  θ(n)  |  θ(n)  |    θ(1)   |   θ(1)   |   O(n)  |  O(n)  |   O(1)    |   O(1)   |        O(n)        |
                +--------+--------+-----------+----------+---------+--------+-----------+----------+--------------------+
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};

struct Node* HEAD=NULL;
struct Node* LAST=NULL;

void display();
void create_first();
void create_last();
void create_any();
void delete_first();
void delete_last();
void delete_any();

int main(){
	int choice;
	while(1){
		printf("Enter Choice:\n1: To create node at first\n2: To create node at last\n3: To create node at any position\n4: To delete node at first\n");
		printf("5: To delete node at last\n6: To delete node at any position\n7: To show the list\n8: To exit the program\n");
		printf("Enter Your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create_first();
				break;
			case 2:
				create_last();
				break;
			case 3:
				create_any();
				break;
			case 4:
				delete_first();
				break;
			case 5:
				delete_last();
				break;
			case 6:
				delete_any();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("\nThank you\n");
				return 0;
			default:
				printf("\nInvalid Choice\n");
		}
		printf("\n\n");
	}
}
void create_any(){
	int index;
	printf("\nEnter index:");
	scanf("%d",&index);
	if(index<1){
		printf("\nInvalid index\nIndex can't be less than 1");
		return;
	}else if(index==1){
		create_first();
		return;
	}else{
		int i=1;
		struct Node* q=HEAD;
		
		while(i<index){
			q=q->next;
			i++;
			if(q==NULL && i<index){
				printf("\nInvalid index!\nIndex out of range");
				return;
			}
		}if(q==NULL){
			create_last();
			return;
		}else{
			struct Node* p=(struct Node*)malloc(sizeof(struct Node*));
			printf("\nEnter data:");
			scanf("%d",&p->data);
			p->next=q;
			p->prev=q->prev;
			q->prev->next=p;
			q->prev=p;
		}
	}printf("\nElement Inserted");
}

void create_last(){
	struct Node* p=(struct Node*)malloc(sizeof(struct Node*));
	printf("\nEnter Number as a data:");
	scanf("%d",&p->data);
	
	if(LAST==NULL){
		HEAD=p;
		LAST=p;
		p->prev=NULL;
		p->next=NULL;
	}else{
		LAST->next=p;
		p->prev=LAST;
		p->next=NULL;
		LAST=p;
	}printf("\nInserted!");
}


void create_first(){
	struct Node* p=(struct Node*)malloc(sizeof(struct Node*));
	printf("\nEnter Number as a data:");
	scanf("%d",&p->data);
	if(HEAD==NULL){
		HEAD=p;
		LAST=p;
		p->prev=NULL;
		p->next=NULL;
	}else{
		p->next=HEAD;
		HEAD->prev=p;
		p->prev=NULL;
		HEAD=p;
	}printf("\nDone!");
}
void delete_first(){
	if(HEAD==NULL){
		printf("\nList is empty\n");
		return;
	}
	struct Node* q=HEAD;
	HEAD=HEAD->next;
	HEAD->prev=NULL;
	free(q);
	printf("\nDone!");
}
void delete_last(){
	if(LAST==NULL){
		printf("\nList is empty\n");
		return;
	}
	struct Node* q=LAST;
	LAST=LAST->prev;
	LAST->next=NULL;
	free(q);
	printf("\nDone!");
}
void delete_any(){
	int index;
	printf("\nEnter index:");
	scanf("%d",&index);
	
	if(index<1){
		printf("\nInvalid index!\nIndex can't be less than 1");
		return;
	}else if(index==1){
		delete_first();
		return;
	}else{
		int i=1;
		struct Node* q=HEAD;
		
		while(i<index){
			q=q->next;
			i++;
			if(q==NULL){
				printf("\nInvalid index!\nIndex out of range");
				return;
			}
		}if(q==LAST){
			delete_last();
			return;
		}
		
		q->next->prev=q->prev;
		q->prev->next=q->next;
		free(q);
	}
	
	printf("\nDeleted!");
}




void display(){
	
	if(HEAD==NULL){
		printf("\nEmpty list\n");
	}else{
		struct Node* q=HEAD;
		printf("\n");
		while(q!=LAST){
			printf("%d ",q->data);
			q=q->next;
		}
		printf("%d",q->data);
	}
}
