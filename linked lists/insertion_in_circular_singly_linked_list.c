/*
                                    Insertion in circular singly linked list
                                    
                    In a circular Singly linked list, the last node of the list contains a pointer to the first node of the list. 
                    We can have circular singly linked list as well as circular doubly linked list.

                    We traverse a circular singly linked list until we reach the same node where we started. 
The circular singly liked list has no beginning and no ending. There is no null value present in the next part of any of the nodes. 
*/
#include<stdio.h>

void beg_insert(); 
void last_insert();  
void display();  

struct node {
    int data;  
    struct node *next;  
};  
struct node* head;
int main(){
    int choice =0; 
    
    while(choice!=4){  
        printf("\ninsertion in circular linked list\n"); 
        printf("\n1.Insert in begining\n2.Insert at last\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice\n");         
        scanf("\n%d",&choice);  
        switch(choice){  
            case 1:  
                beginsert();      
                break;  
            case 2:  
                lastinsert();         
                break;
            case 3:
               display();
               break;
            case 4:  
                exit(0);  
                break;  
            default:  
                printf("Please enter valid choice..");  
                
        }  
    }  
}  

void beginsert(){  
    struct node *ptr,*temp;   
    int item;   
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOVERFLOW");  
    }else{  
        printf("\nEnter the node data?");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(head == NULL){  
            head = ptr;  
            ptr -> next = head;  
        }else{     
            temp = head;  
            while(temp->next != head)  
                temp = temp->next;  
            ptr->next = head;   
            temp -> next = ptr;   
            head = ptr;  
        }printf("\nnode inserted\n");  
    }  
              
}  
void last_insert(){  
    struct node *ptr,*temp;   
    int item;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOVERFLOW\n");  
    }else{  
        printf("\nEnter Data?");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(head == NULL){  
            head = ptr;  
            ptr -> next = head;    
        }else{  
            temp = head;  
            while(temp -> next != head){  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }printf("\nnode inserted\n");  
    }  
  
}  
void display(){  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL){  
        printf("\nnothing to print");  
    }else{  
        printf("\n printing values ... \n");  
          
        while(ptr -> next != head){  
          
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }printf("%d\n", ptr -> data);  
    }  
              
}  
