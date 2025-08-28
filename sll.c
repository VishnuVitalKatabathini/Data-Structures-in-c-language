#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node * next;
}node;


 
// create node
node* create(int val, node *head)
{
    node *newnode=NULL;
    newnode=(node*)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;

}
// create node
node* ins_pos(int val,int pos,node *head)
{
    node *newnode=NULL,*temp=NULL;
    newnode=(node*)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        int i=0;
       temp=head;
       while(temp->next!=NULL){
        temp=temp->next;
        i++;
       }
       newnode->next=temp->next;
       temp->next=newnode;

    }
    return head;

}
void display(node *head){
    node* temp=head;
    printf("head->");
    while(temp!=NULL){
        
        printf("%d->",temp->val);
        temp=temp->next ;  
    }
    
}
void main()
{  
    node* head=NULL;
    int x,pos;
    for(int i=0;i<5;i++)
    {
        printf("vale x");
        scanf("%d",&x);
        head=create(x,head);
    }
    display(head);
    printf("vale x");
    scanf("%d",&x);
    printf("pos=");
    scanf("%d",&pos);
    head=ins_pos(x,pos,head);
    display(head);
    
    
}

