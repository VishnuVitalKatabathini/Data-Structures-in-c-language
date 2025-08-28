#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;

};

struct node* create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=0;
    return newnode;
}

struct node* insert(struct node *root,int data)
{
    struct node *newnode=create(data);
    struct node *temp=root;
    struct node *ptr=0;
    while(temp!=0)
    {
        ptr=temp;
        if(data<temp->data)
            temp=temp->left;
        else    
            temp=temp->right;
        
    }
    if(ptr==0)
    {
        ptr=newnode;
        return ptr;
        
    }
    else if(ptr->data>data)
            ptr->left=newnode;
    else 
        ptr->right=newnode;
    
}
void inorder(struct node * root)
{
    if(root!=0)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if(root!=0)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void main()
{
    struct node *root=0;
    root=insert(root,90);
    insert(root,78);
    insert(root,100);
    insert(root,110);
    insert(root,12);
    insert(root, 56);
    insert(root,34);
    inorder(root);
    printf("\n");
    preorder(root);
}