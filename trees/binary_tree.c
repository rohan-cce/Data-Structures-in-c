#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct node *left;
    struct node *right;
};

struct Node* create(int data){
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->data= data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void preorder_traversal(struct Node *root){
    if (root != NULL){
        printf("%d\n", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    else return;
}

void inorder_traversal(struct Node *root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d\n", root->data);
        inorder_traversal(root->right);
    }else return;
}

void postorder_traversal(struct Node *root){
    if(root != NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d\n",root->data);
    }
    else return;
}

int main(){
    struct Node *root= create(4);
    root->left= create(3);
    root->right= create(5);
    printf("printing pre order traversal : \n");
    preorder_traversal(root);

    printf("printing in order traversal : \n");
    inorder_traversal(root);

    printf("printing post order traversal: \n");
    postorder_traversal(root);
}
