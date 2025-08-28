#include<stdio.h>
#include<stdlib.h>
struct node { //this is just an overview of  basic binary tree implementation
    int data;
    struct node *left,*right;
};
struct node* create_tree()
{
    int val;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data :\n");
    scanf("%d",&val);
    
    if(val==-1)
    {
        return 0;
    }
   
    
         newnode->data=val;
        printf("assigning left node to the %d\n",newnode->data);
        newnode->left=create_tree();
        printf("assigning right node to the %d\n",newnode->data);
        newnode->right=create_tree();
    
    return newnode;
}
void preorder_traversal(struct node *root)// logic for  preorder traversal of binary tree
{
    if(root==0)
    {
        
        return ;
    }
  
        printf("%d->",root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);

    
}
void inorder_traversal(struct node *root)
{
    if(root==0)
    {
        return ;
    }
    
    inorder_traversal(root->left);
    printf("%d->",root->data);
    inorder_traversal(root->right); 
}
void postorder_traversal(struct node *root)
{
 if(root==0)
 {
    return;

 }
 postorder_traversal(root->left);
 postorder_traversal(root->right);
 printf("%d->",root->data);
}
void main()
{
    struct node *root=0;
    root=create_tree();
    printf(".......preorder_traversal....... \n");
    preorder_traversal(root);
    printf("\n...........inroder taversal...........\n");
    inorder_traversal(root);
    printf("\n postorder traversal\n");
    postorder_traversal(root);
}