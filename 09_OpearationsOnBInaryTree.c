#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node * createBinTree(){
    int data;
    int choice;
    printf("Enter the data : ");
    scanf("%d",&data);
    struct node * root = createNode(data);
    printf("Do you have left Node :(1/0) ");
    scanf("%d",&choice);
    if (choice==1){
        root->left=createBinTree();
    }
    printf("Do you have right Node :(1/0) ");
    scanf("%d",&choice);
    if (choice==1){
        root->right=createBinTree();
    }
    return root;
}

void inOrderTraversal(struct node * root){
    if (root!=NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}

int height(struct node* root){
    if (root==NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int height = (leftHeight>rightHeight ? leftHeight : rightHeight ) + 1;
    return height;
}

int diameter(struct node* root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int leftdia = diameter(root->left);
    int rightdia = diameter(root->right);

    int maxdia= (leftheight+rightheight)+1;

    return ((leftdia>rightdia)?((leftdia>maxdia)?leftdia:maxdia):((rightdia>maxdia)?rightdia:maxdia));
}

int main(){
    struct node * root = createBinTree();
    inOrderTraversal(root);
    int ht = height(root);
    printf("\nHeight : %d",ht);
    int dia = diameter(root);
    printf("\nDiameter : %d",dia);
}

/* 
    Algorithm for creating a binary tree:
    1. Create a new node with the given data.
    2. Ask the user if the node has a left child:
        - If yes, recursively create the left child by calling createBinTree() and assign it to the left pointer of the current node.
    3. Ask the user if the node has a right child:
        - If yes, recursively create the right child by calling createBinTree() and assign it to the right pointer of the current node.
    4. Return the created node.

    Algorithm for in-order traversal:
    1. If the root is NULL, return.
    2. Recursively call inOrderTraversal() on the left subtree.
    3. Print the data of the current node.
    4. Recursively call inOrderTraversal() on the right subtree.

    Algorithm to find the height of a binary tree:
    1. If the root is NULL, return 0 (height of an empty tree is 0).
    2. Recursively find the height of the left subtree.
    3. Recursively find the height of the right subtree.
    4. Return the maximum of the left and right subtree heights, plus 1 to account for the current node.

    Algorithm to find the diameter of a binary tree:
    1. If the root is NULL, return 0 (diameter of an empty tree is 0).
    2. Calculate the height of the left subtree.
    3. Calculate the height of the right subtree.
    4. Recursively calculate the diameter of the left and right subtrees.
    5. Calculate the current diameter as the sum of the left and right subtree heights, plus 1 for the current node.
    6. Return the maximum value between:
        - The diameter of the left subtree.
        - The diameter of the right subtree.
        - The current diameter of the tree.
*/
