/*to do list using linked list concept */

#include <stdio.h>
#include <stdlib.h>


void create();
void del();
void see();
void fixcount();

struct ToDo{
 char data[100];
 struct ToDo *link;
 int count;
};

struct ToDo *start=NULL;
int main(){
    int choice;
    while(1){
        system("cls");
        printf("\t#################################### YOUR TODO LIST APP ##############################################\n\n");
        printf("\n\t1.Create Your ToDos");
        printf("\n\t2.Delete Your ToDos");
        printf("\n\t3.See Your ToDo List");
        printf("\n\t4.Exit");
        printf("\n--------------------------------------------------------------------------------------------------");
        printf("\n\nEnter your choice..");
        scanf("%d",&choice);
        switch(choice){
      case 1:
          create();
          break;
      case 2:
          del();
          break;
      case 3:
          see();
          break;
      case 4:
      printf("Thank you !");
        exit(0);
      default:
          printf("Enter correct option");
        }
    }
}

void see(){
  system("cls");
   struct ToDo *temp;
   temp=start;
        printf("\t***Your Todo's are***\n");
        if(start==NULL){
           printf("\nEmpty TODO\n\n");
        }
        printf("---------------------------------------\n");
       while(temp!=NULL){
          printf("\t%d)",temp->count);
          puts(temp->data);
          fflush(stdin);
          temp=temp->link;
       }
       
        printf("\n-------------------------------------\n");
        system("pause");
   }

void create(){
  system("cls");
    char k;
    struct ToDo *t,*temp;
    while(1){
        printf("\nWant to add?y/n : ");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
       else{
        if(start==NULL){
        t=(struct ToDo *)malloc(sizeof(struct ToDo));
        start=t;
        printf("\nADD It Below.. : \n");
        fflush(stdin);
        gets(t->data);
        t->count=1;
        start->link=NULL;
       }
       else{
       temp=(struct ToDo *)malloc(sizeof(struct ToDo));
       printf("\nADD it..\n");
       fflush(stdin);
       gets(temp->data);
       temp->link=NULL;
       t->link=temp;
       t=t->link;
     }
     fixcount();
    }
   }
}

void del(){
  system("cls");
  int d;
  struct ToDo *temp1,*temp;
  printf("\nEnter the no of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }else{
        temp1=temp;
        temp=temp->link;
    }
}system("pause");
}

void fixcount(){
  struct ToDo *temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

