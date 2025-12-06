#include <stdio.h>
#include <stdlib.h>

// Structure for the nodes
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);  // No space -> prints 21654
    }
}

// The tree is:
//        4
//       / \
//      1   5
//     / \
//    2   6
int main() {
    struct node* p = createnode(4);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(5);
    struct node* p3 = createnode(2);
    struct node* p4 = createnode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    postorder(p);   // Output: 21654
    return 0;
}