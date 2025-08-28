#include<stdio.h>
#include<stdlib.h>
void create_node();
void insertatbeg();
void display();
void deleteatbeg();
void insertatposition();
void deleteatposition();
typedef struct doublylinkedlist
{
   int rollno;
   char name[12];
   struct doublylinkedlist *next,*prev;  
}dll;
dll *head=0,*tail=0;
void create_node()
{
   dll *node,*temp=0;
   node=(dll*)malloc(sizeof(dll));
   printf("enter char name:\n");
   scanf("%s",node->name);
   printf("enter rollno:");
   scanf("%d",&node->rollno);
   node->next=0;
   node->prev=0;
   if(head==0&&tail==0)
   {
      head=node;
   }
   else
   {
      temp=head;
      while(temp->next!=0)
      {
         temp=temp->next;
      }
      temp->next=node;
      node->prev=temp;
   }
}
void insertatbeg()
{
    dll *node,*temp=0;
   node=(dll*)malloc(sizeof(dll));
   printf("enter char name:\n");
   scanf("%s",node->name);
   printf("enter rollno:");
   scanf("%d",&node->rollno);
   node->next=0;
   node->prev=0;
   if(head==0&&tail==0)
   {
      head=node;
   }
   else{
      temp=head;
      node->next=head;//node->next=temp;
      head->prev=node;//temp->prev=node;
      head=node;

   }
}
void insertatposition()
{
   int pos;
   printf("enter position to insert:\n");
   scanf("%d",&pos);
   dll *node,*temp=0;
   node=(dll*)malloc(sizeof(dll));
   printf("enter char name:\n");
   scanf("%s",node->name);
   printf("enter rollno:");
   scanf("%d",&node->rollno);
   node->next=0;
   node->prev=0;
   if(head==0&&tail==0)
   {
      head=tail=node;

   }
   else{
      temp=head;
      for(int i=1;i<pos-1;i++)
      {
         temp=temp->next;
      }
      node->next=temp->next;
      temp->next=node;
      node->prev=temp;
      
   }
}
void display()
{
    dll *temp=0;
    if(head==0)
    {
      printf("list is empty.....!");

    }
    else
    {
      temp=head;
      printf("head->");
      while(temp!=0)
      {
         printf("rollno=%d:%s<->",temp->rollno,temp->name);
         temp=temp->next;
      }
      printf("NULL\n");
    }
}
void deleteatbeg()
{
   dll *temp=0;
   if(head ==0)
   {
      printf("list is empty \n");
   }
   else{
      temp=head;
      head=head->next;
      head->prev=0;
      free(temp);
   }
}
void deleteatposition()//this also works for delete at end operation
{
   int pos;
   dll *temp=0,*p=0,*ptr=0;
   if(head==0)
   {
      printf("list is empty\n");
   }
   
   else{
      temp=head;
      printf("enter position to delete:\n");
      scanf("%d",&pos);
      for(int i=1;i<pos-1;i++)
      {
         temp=temp->next;
      }
      p=temp->next;
      ptr=p->next;
      ptr->prev=p->prev;
      temp->next=ptr;
      free(p);
   }
}

void main()
{
    int ch;
 while(1)
 { 
    printf("choose an option below\n");
    printf("1.create_node()\n");
    printf("2.insertatbeg()\n");
    printf("3.insertatposition()\n");
    printf("4.deleteatbeg()\n");
    printf("5.display()\n");
    printf("6.deleteatposition()\n");
    printf("7.exti(0)\n");
    printf("enter your choice:\n");
    scanf("%d",&ch);
    switch (ch)
    {
     case 1:
          create_node();
        break;
     case 2:
        insertatbeg();
        break;
     case 3:
       insertatposition();
       break;
     case 4:
        deleteatbeg();
        break;
     case 5:
       display();
       break;
     case 6:
        deleteatposition();
        break;
     case 7:
      exit(0);
     default:
      printf("ennter valid choice....!\n");
        break;
    }
  }
}