#include<stdio.h>
#include<stdlib.h>
 struct node
{
    int data;
    struct node *next;
};
struct node *head=0;
void push(int data)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void pop()
{
     struct node *temp=0;
    if(head==0)
    {
        printf("struct node underflow.......\n");
    }
    else
    {
        temp=head;
        printf("poped element is %d",head->data);
        head=head->next;
        free(temp);
    }
}
void display()
{
    if(head==0)
        printf("struct node is empty\n");
    else
    {
        struct node *temp=head;
        while(temp!=0)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void  main()
{
    push(20);
    push(80);
    push(50);
    display();
    pop();
    display();
}