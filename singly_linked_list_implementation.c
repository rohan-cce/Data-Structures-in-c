/*Single linked list implementation using dynamic memory allocation

    Linked List can be defined as collection of objects called nodes that are randomly stored in the memory.
    A node contains two fields i.e. data stored at that particular address and the pointer which contains the address of the next node in the memory.
    The last node of the list contains pointer to the null.     
   
                                                            Linked list
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
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* head;

void append();
int main(){    
    while(1){
    printf("Choose a operation to be performed:\n");
    printf("1.To append(add at end) a node\n2.To add node at begin when other nodes are there too\n3.To add a node after a particular node\n4.To display all data\n5.To delete a node\n6.To find length\n7.exit");
        int n;
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n){
        case 1: 
             append();
             printf("Node created\n");
             break;               
        case 2: 
             NodeAtBegin();
             break;      
        case 3: 
             NodeAfter();
             break;             
        case 4: 
             display();
             break;
        case 5: 
             del();
             break;             
        case 6: 
             int len = length();
             printf("List has %d nodes/data\n",len);
             break;
        case 7:  
             exit(0);
        default:
             printf("Invalid input\n");
        }
    }

    return 0;
}



void append(){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d",&ptr->data);
    ptr->link = NULL;
    if(head == NULL)
        head=ptr;
    else{
            struct node* x = root;
            while(x->link!=NULL){
                x=x->link;
            }
            x->link = ptr;
        }
}


void NodeAtBegin(){
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d",&ptr->data);
    ptr->link=NULL;
    if(head==NULL){
        head=ptr;
    }else{
        ptr->link=head;
        head=ptr;
    }
    printf("Node added\n");
}


void NodeAfter(){
    int n,i=1,len;
    printf("Enter no after which u want to add node: ");
    scanf("%d",&n);
    len = length();
    if (n>len){
        printf("Invalid location\n");
        printf("Currently list is having %d nodes\n",len);
    }else{
        struct node* ptr,* x=head;
        ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d",&ptr->data);
        ptr->link = NULL;
        while(i<n){
            x=x->link;
            i++;
        }
        ptr->link=x->link;
        x->link=ptr;
        printf("Node entered after %d nodes\n",n);
    }

}


void display(){
    struct node* x=head;
    printf("Elements are: ");
    if(head=NULL)
        printf("List is empty");
    else{
        while(x!=NULL){
            printf("%d  ",x->data);
            x=x->link;
        }
    }
    printf("\n");
}


void del(){
        int n;
        printf("Enter location to delete: ");
        scanf("%d",&n);
        struct node* x=head;
    if (n>length())
        printf("Invalid location\n");
    else if(n==1){
        x=head;
        head= x->link;
        x->link=NULL;
        free(x);
        printf("Node deleted\n");
    }else{
        int i=1;
        struct node* p=head;
        while(i<n-1){
            x=x->link;
            i++;
        }
        p=x->link;
        x->link=p->link;
        p->link=NULL;
        free(p);
        printf("Node deleted\n");
    }
}


int length(){
    struct node* x;
    x=head;
    int count=0;
    if(head==NULL)
        return 0;
    else{
        while(x!=NULL){
            x=x->link;
            count++;
        }
        return count;
    }
}
