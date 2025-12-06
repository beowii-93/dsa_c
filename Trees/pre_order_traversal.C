#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//Creating a function with the null binary tree
struct node* createnode(int data){
    struct node* n; // Creating a node pointer
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
 void preorder(struct node* root){
     //if ur root is not null then print ur root data only
     if(root != NULL){
         printf("%d",root->data);
         //Recursion
         preorder(root->left);
         preorder(root->right);
     }
 }
//  The tree is represented as 
//   4
//   /\
//   1  2
//   /\
//  6  8
   
 int main(){
     
     struct node *p=createnode(4);
     struct node *p1=createnode(1);
     struct node *p2=createnode(2);
     struct node *p3=createnode(6);
     struct node *p4=createnode(8);
     
     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;
     preorder(p);
     return 0;
     
 }