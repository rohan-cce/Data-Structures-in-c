#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* create(int data) {
    //return the pointer for the new node
    struct node *ptr= (struct node *)malloc(sizeof(struct node));
    ptr->data= data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preorder_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d\n", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    else return;
}

void inorder_traversal(struct node *root) {
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d\n", root->data);
        inorder_traversal(root->right);
    }
    else return;
}

void postorder_traversal(struct node *root) {
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d\n",root->data);
    }
    else return;
}

int main() {
  
}
