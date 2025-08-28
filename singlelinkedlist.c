#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}singlelist;
singlelist *head=0;
void create_list()
{
    singlelist *newnode,*temp=0;
    newnode=(singlelist*)malloc(sizeof(singlelist));
    printf("enter data:\n");
    scanf("%d",&(newnode->data));
     newnode->next=0;
     if(head==0)
     {
        head=newnode;
     }
     else
     {
        temp=head;
        while (temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
     }
}
void insert_at_beg()
{
    singlelist *newnode;
    newnode=(singlelist*)malloc(sizeof(singlelist));
    printf("enter data");
    scanf("%d",&(newnode->data));
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
void insert_at_pos()
{
    int pos;
    singlelist *newnode,*temp=0;
    newnode=(singlelist*)malloc(sizeof(singlelist));
    printf("enter data\n");
    scanf("%d",&(newnode->data));
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
    }
    else{
        printf("enter position to enter\n");
        scanf("%d",&pos);
        temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

    }
}
void display()
{
    singlelist *temp=head;
    if(head==0)
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
void delete_at_beg()
{
    singlelist *temp=0;
    if(head==0)
    {
        printf("lsit is empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
void delete_at_pos()
{
    int pos;
    singlelist *temp=0,*ptr=0;
    if(head==0)
    {
        printf("list is empty\n");
    }
    else{
        printf("enter position to delete:\n");
        scanf("%d",&pos);
        temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;

        }
        ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
    }
}
void reverse_list()
{
    singlelist *temp=0,*prev=0,*curr=0;
    if(head==0)
    {
        printf("lsit is empty\n");
    }
    else
    {
        temp=prev=curr=head;
        while(temp!=0)
        {
            temp=temp->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head->next=0;
        head=prev;
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("choose one operation below\n");
        printf("1.create_list()\n");
        printf("2.display()\n");
        printf("3.insert_at_beg()\n");
        printf("4.insert_at_pos()\n");
        printf("5.delete_at_beg()\n");
        printf("6.delete_at_pos()\n");
        printf("7.reverse_list()\n");
        printf("8.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            create_list();
                break;
             case 2:
             display();
                break;
            case 3:
            insert_at_beg();
                break;
            case 4:
            insert_at_pos();
                break;
            case 5:
                delete_at_beg();
                break;
             case 6:
                delete_at_pos();
                break;
           case 7:
            reverse_list();
                break;
             case 8:
              exit(0);
            break;
        default:
            break;
        }
    }
}
