// Linked representation of the binary tree in C language
#include <stdio.h>
#include <stdlib.h> // or <malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
//We are creating a node which returns the binary tree
struct node *createNode(int data){
    struct node *n; 
    n= (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
//Constructing the nodes using the normal method of creating indivdual nodes
    /*
    struct node *p; //root node
    p= (struct node*)malloc(sizeof(struct node));
    p->data=2;
    p->left=NULL;
    p->right=NULL;
    
    struct node *p1;//first node
    p1=(struct node*)malloc(sizeof(struct node));
    p1->data=1;
    p1->left=NULL;
    p1->right=NULL;
    
    struct node *p2;//second node
    p2=(struct node*)malloc(sizeof(struct node));
    p2-data=4;
    p2->left=NULL;
    p2->right=NULL; 
    */
    
// Constructing the nodes using fuction of creatNode
struct node *p = createNode(2);
struct node *p1 = createNode(1);
struct node *p2 = createNode(4);
 
    //linking the node
    p->left=p1;
    p->right=p2;
    return 0;
}