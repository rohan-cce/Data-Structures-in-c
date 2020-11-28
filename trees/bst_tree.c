//binary search tree implementation in c
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right_child; 
    struct node *left_child; 
};

struct node* search(struct node *root, int x){
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->right_child, x);
    else
        return search(root->left_child,x);
}
struct node* find_minimum(struct node *root){
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) 
        return find_minimum(root->left_child); 
    return root;
}



struct node* insert(struct node *root, int x){
	if(root==NULL){
	root = (struct node*)malloc(sizeof(struct node ));
    root->data = x;
    root->left_child = NULL;
    root->right_child = NULL; 
  }else if(x>root->data) 
        root->right_child = insert(root->right_child, x);
    else 
        root->left_child = insert(root->left_child,x);
    return root;
}



struct node* deletee(struct node *root, int x){
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = deletee(root->right_child, x);
    else if(x<root->data)
        root->left_child = deletee(root->left_child, x);
    else{
        if(root->left_child==NULL && root->right_child==NULL){
            free(root);
            return NULL;
        }else if(root->left_child==NULL || root->right_child==NULL){
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }else{
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = deletee(root->right_child, temp->data);
        }
    }
    return root;
}

struct node* findmin(struct node *root){
    if(root==NULL)
        return NULL;
    else if(root->left_child==NULL)
        return root;
    else
        return findmin(root->left_child);
}
struct node* findmax(struct node *root){
    if(root==NULL)
        return NULL;
    else if(root->right_child==NULL)
        return root;
    else
        return findmin(root->right_child);
}


void inorder(struct node *root){
    if(root!=NULL) {
        inorder(root->left_child); 
        printf(" %d ", root->data); 
        inorder(root->right_child);
    }
}

void preorder(struct node *root){
    if(root!=NULL){        
        printf(" %d ", root->data); 
	      preorder(root->left_child); 
        preorder(root->right_child);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left_child); 
        postorder(root->right_child);
	printf(" %d ", root->data);
    }
}

int main(){
	struct node *root,*a,*b,*c;
    int ch,n,x,s;
    root=NULL;
    
    while(1){
        printf("\n1 insert\n2 Delete an element from the tree\n3 Inorder Traversal\n4 Preorder Traversal\n5 Postorder Traversal\n6 Find Minimum element\n7 Find maximum element\n8 - Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:  
	          printf("Enter the node to be inserted \n");
	          scanf("%d",&x);
	          root=insert(root,x);
            break;
        case 2:    
		        printf("Enter the node to be deleted \n");
		        scanf("%d",&n);
            root=deletee(root,n);
            break;
        case 3:    
            inorder(root);
            break;
        case 4:    
            preorder(root);
            break;
        case 5:    
            postorder(root);
            break;
	    case 6:
		    a=findmin(root);
		    printf("%d",a->data);
	        break;
	    case 7:
	        b=findmax(root);
	        printf("%d",b->data);
	        break;
	      case 8:
		       printf("Enter the element to be searched \n");
		       scanf("%d",&s);
	        	if(search(root,s))
		            printf("Element found %d",s);
		        else
		          	printf("Element not found %d",s);
        case 9:    
            exit(0);
        default :     
            printf("Wrong choice, Please enter correct choice  ");
            break;    
        }
    }
    return 0;
}
