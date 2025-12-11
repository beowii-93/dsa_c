#include <stdio.h>
#include <malloc.h>
//Create a structure for the nodes
struct node{
    int data;
    struct node* left;
    struct node* right;
};
//Create a function to create node
struct node* createnode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data =data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//previous node pointer for pointing to the previous node
struct node* prev=NULL;

void inorder(struct node* root){
    //tO GET THE ascending order of the elements as if it is bst it will give the sorted order
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
//To check whether the tree is BST or not
int isBST(struct node* root){
    //if the root is not null,it will check for the left subtree first
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        //then later the current node will be checked with the previous node
        //if the previous node's data is greater than or equal to the current node's data ,then condition fails
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        //updating the previous node to the current node because we are moving to the right subtree now
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}


// The tree representation
//      4
//     / \
//     3  6
//   /\
//  1  4
 
 int main(){
    struct node* p=createnode(4);
    struct node* p1=createnode(3);
    struct node* p2=createnode(6);
    struct node* p3=createnode(1);
    struct node* p4=createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    
    inorder(p);
    printf("%d",isBST(p));
    return 0;
 }