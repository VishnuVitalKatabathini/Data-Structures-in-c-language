#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}bst;

bst* createbst(int data)
{
    bst *newnode,*temp=0;
    newnode=(bst*)malloc (sizeof(bst));
    newnode->data=data;
    newnode->left=newnode->right=0;
    return newnode;

}
bst* insertbst(bst *root,int data)
{
    

    if(root==0)
    {
        return createbst(data);
    }
    if(data<root->data)
    {
        root->left=insertbst(root->left,data);
    }
    else
    {
        root->right=insertbst(root->right,data);
    }


}
void searchbst(bst *root,int data)
{
    if(root==0)
    {
        printf("\nsearch unsuccessfull\n");
    }
    else if(root->data==data)
    {
        printf("\nsearch successfull\n");
        printf("\n%d=%d\n",root->data,data);
    }
    else if(data<root->data)
    {
        searchbst(root->left,data);
    }
    else
        searchbst(root->right,data);

}
void inorderTraversal(bst *root)
{
    if(root==0)
        return ;
    inorderTraversal(root->left);
    printf("%d->",root->data);
    inorderTraversal(root->right);

}
bst *minValueNode(bst *node) {
  bst *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}
bst* deletebst(bst *root,int key)
{
    if (root == NULL)
    return root;

  if (key < root->data)
    root->left = deletebst(root->left, key);

  else if (key > root->data)
    root->right = deletebst(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      bst *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      bst*temp = minValueNode(root->right);

      root->data = temp->data;

      root->right = deletebst(root->right, temp->data);
    }
  }

    return root;
}

void main()
{
    int ch,val;
  bst * root=0;
  while(1)
  {
    printf("\nchoose an option below\n");
    printf("\n1.insertbst\n");
    printf("\n2.inorderTraversal\n");
    printf("\n3.searchbst\n");
    printf("\n4.deletenode\n");
    printf("\nenter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nenter data:\n");
            scanf("%d",&val);
            root=insertbst(root,val);
            break;
        case 2:
            printf("\n....................inorder Traversal................\n");
            inorderTraversal(root);
            break;
        case 3:
            printf("\nenter data to search:\n ");
            scanf("%d",&val);
            searchbst(root,val);
            break;
        case 4:
        printf("enter data to delete:\n");
        scanf("%d",&val);
           root=deletebst(root,val);
           break;
        case 5:
           exit(0);

    }


  }
}