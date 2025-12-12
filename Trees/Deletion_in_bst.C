#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// inOrderPredecessor: left subtree's  rightmost child
struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *delete (struct node *root, int value)
{
    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    { // A leaf node
        free(root);
        return NULL;
    }
    // search the node to be deleted
    if (value < root->data)
    {
        root->left = delete (root->left, value); // in order to reduce the problem of searching the value
    }
    else if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    // Once the node is found ,we can replace it with the predecessor successor
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;                      // copy to the pre
        root->left = delete (root->left, iPre->data); // delete the pre once copied to the deleted node.
        // It runs recursively
    }
    return root;
}

// The tree representation
//      4
//     / \
//     2  6
//   /\
//  1  3
int main()
{
    struct node *p = createnode(4);
    struct node *p1 = createnode(2);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(3);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inorder(p);
    printf("\nBefore deleting the data:%d\n", p1->data);
    delete (p, 2);
    printf("After deletion:");
    inorder(p);
    printf("\nAfter deleting the data:%d", p1->data); // It got replaced with one
    printf("\n%d", p3->data);                         // Its giving random memory allocation
    return 0;
}
