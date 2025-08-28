#include<stdio.h>
#include<stdlib.h>
 struct node
{
    int data;
    struct node *next;
};
struct node *f=0,*r=0;  
void enqueue(int data)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
     newnode->next=0;
     if(f==0&&r==0)
     {
        f=r=newnode;
     }
     else
     {
        r->next=newnode;
        r=r->next;
        
     }
}
void dequeue()
{
    struct node *temp=0;
    if(f==0&&r==0)
    {
        printf("struct node under flow\n");
    }
    else if(f==r)
    {
        printf("deleted element is %d\n",f->data);
        f=r=0;
    }
    else
    {
        printf("deleted element is %d\n",f->data);
        temp=f;
        f=f->next;
        free(temp);
    }
}
void display()
{
    struct node *temp=f;
    if(f==0&&r==0)
    {
        printf("list is empty\n");

    }
    else{
        printf("head->");
        while(temp!=0)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
        
    }
}
void main()
{
    enqueue(20);
    enqueue(30);
    enqueue(2);
    enqueue(290);
    display();
    dequeue();
    display();
}
