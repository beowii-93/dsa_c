#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int item;
    struct node* left;
    struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) 
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->item);
    inorderTraversal(root->right);
    }

// Preorder traversal
void preorderTraversal(struct node* root) 
{
    if (root == NULL) return;
    printf("%d ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) 
{
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->item);
}

// Create a new Node
struct node* create(int value) 
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) 
{
    root->left = create(value);
    return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) 
{
    root->right = create(value);
    return root->right;
}


struct node* search(struct node * tree, int val)
{
    if(!(tree))
    {
        return NULL;
    }

    if(val == tree->item)
    {
         return tree;
         
    }
    else if(search(tree->left, val)==NULL)
    {
        search(tree->right, val);
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}


int main() 
{
    struct node* root = create(1);
    insertLeft(root, 4);
    insertRight(root, 6);
    insertLeft(root->left, 9);
    insertRight(root->left, 3);
    insertLeft(root->right, 2);
    insertRight(root->right, 8);

    printf("Traversal of the inserted binary tree \n");
    printf("Inorder traversal \n");
    inorderTraversal(root);

    printf("\nPreorder traversal \n");
    preorderTraversal(root);


    printf("\nPostorder traversal \n");
    postorderTraversal(root);

    printf("\nheight of the tree: %d\n", height(root));


    struct node *tmp;
    tmp = search(root, 8);
    if (tmp)
    {
        printf("\nSearched node=%d in the tree\n", tmp->item);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
    
    tmp = search(root, 99);
    if (tmp)
    {
        printf("\nSearched node=%d in the tree\n", tmp->item);
    }
    else
    {
        printf("%d Not found in tree.\n", 99);
    }

  
}



