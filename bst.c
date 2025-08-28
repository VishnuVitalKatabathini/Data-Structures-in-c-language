#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *right,*left;
    int height;
}bst;

bst *create(int data)
{
    bst *newnode=(bst*)malloc(sizeof(bst));
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    newnode->height=1;
    return newnode;
}

bst *insert(bst * root,int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    if(data==root->data)
    {
        printf("/ndata already exist in the list\n");
    }
    return root;
}

bst *delete( bst *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    if(data<root->data)
    {
        root->left=delete(root->left,data);
    }
    if(data>root->data)
    {
        root->right=delete(root->right,data);
    }
    if(root->left==NULL||root->right==NULL)
    {
        bst *temp=root->left?root->left:root->right;
        if(temp==NULL) //if both the left child node and right child node is null
        {
            temp=root;
            root=NULL;
        }
        else // if any one of the children of root node is  not null
            *root=*temp;
            free(temp);
    }
    else //if both the children of the root node is not null
    {
        bst *leftside=root->left;
        bst *greater;
        while(leftside->right!=NULL)
        {
            leftside=leftside->right;
        }
        greater=leftside;
        root->data=greater->data;
        free(greater);
        root->left=delete(root->left,data);
    }
    return root;
}
void inorder(bst *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);

}
void  main()
{
    bst *root=NULL;
     int ch,val;
  while(1)
  {
    printf("\nchoose an option below\n");
    printf("\n1.insertbst\n");
    printf("\n2.inorderTraversal\n");
    printf("\n3.deletenode\n");
    printf("\nenter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nenter data:\n");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 2:
            printf("\n....................inorder Traversal................\n");
            inorder(root);
            break;
        case 3:
              printf("enter data to delete:\n");
              scanf("%d",&val);
              root=delete(root,val);
              break;
        case 4:
           exit(0);

    }


  }
   
}