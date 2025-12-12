#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void insert(struct node *root,int key){
    struct node *prev =NULL;
    while(root!= NULL){
        prev = root;
        if(key==root->data){ //If on finding the root as key ,then return ,we needn't insert the key anymore
        printf("Cannot insert %d ,already in binary tree!\n",key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else if(key>root->data){
            root=root->right;
        }
    }
    
    struct node* new=createnode(key);
    if(key<prev->data){
        prev ->left = new;
    }
    else{
        prev ->right = new;
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
    insert(p,7);
    insert(p,2);
    insert(p,3);
    inorder(p);
    return 0;
}

