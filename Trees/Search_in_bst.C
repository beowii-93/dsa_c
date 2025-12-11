#include <stdio.h>
#include <malloc.h>
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

struct node *prev = NULL;

void inorder(struct node *root)
{
    // tO GET THE ascending order of the elements as if it is bst it will give the sorted order
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root)
{
    // if the root is not null,it will check for the left subtree first
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        // then later the current node will be checked with the previous node
        // if the previous node's data is greater than or equal to the current node's data ,then condition fails
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        // updating the previous node to the current node because we are moving to the right subtree now
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

// The tree representation
//      4
//     / \
//     3  6
//   /\
//  1  4
int main()
{
    struct node *p = createnode(4);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    if (isBST(p))
    {
        printf("This is a bst");
    }
    struct node *element = search(p, 6);
    if (element != NULL)
    {
        printf("FOUND: %d", element->data);
    }
    else
    {
        printf("Element not found.");
    }
    return 0;
}
 
        