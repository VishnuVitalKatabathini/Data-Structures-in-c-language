#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
    int height;
};
struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = 0;
    newnode->height = 1;
    return newnode;
}
int getheight(struct node *root)
{
    if (root == 0)
        return 0;
    return root->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getbalance(struct node *root)
{
    if (root == 0)
        return 0;
    return getheight(root->left) - getheight(root->right);
}
struct node *rotateleft(struct node *root)
{
    struct node *lr = root->right;
    struct node *ll = lr->left;
    lr->left = root;
    root->right = ll;
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    lr->height = 1 + max(getheight(lr->left), getheight(lr->right));
    return lr;
}
struct node *rotateright(struct node *root)
{
    struct node *rr = root->left;
    struct node *rl = rr->right;
    rr->right = root;
    root->left = rl;
    rr->height = 1 + max(getheight(rr->left), getheight(rr->right));
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    return rr;
}
struct node *insert(struct node *root, int data)
{
    if (root == 0)
    {
        return create(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int balance = getbalance(root);

    if (balance > 1 && data < root->left->data)
        return rotateright(root);

    if (balance < -1 && data > root->right->data)
        return rotateleft(root);

    if (balance > 1 && data > root->left->data)
    {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}
void preordertraversal(struct node *root)
{
    if (root != 0)
    {
        printf("%d\t", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
struct node *delete(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete (root->left, key);

    else if (key > root->data)
        root->right = delete (root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = delete (root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int balance = getbalance(root);
    if (balance > 1 && getbalance(root->left) >= 0)
        return rotateright(root);

    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }

    if (balance < -1 && getbalance(root->right) <= 0)
        return rotateleft(root);

    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }

    return root;
}
void main()
{
    struct node *root = 0;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    printf("pre-order traversal\n");
    preordertraversal(root);
    root = delete (root, 3);
    printf("\navl tree after deletion\n");
    preordertraversal(root);
}