#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;
    return newNode;
}

struct node* insertNode(struct node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if (data < root->data){
        root->left=insertNode(root->left,data);
    }
    if(data>root->data){
        root->right=insertNode(root->right,data);
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

int main(){
    int choice,data;
    struct node * root=NULL;
    printf("How many data do you want to insert :");
    scanf("%d",&choice);
    for (int i=0;i<choice;i++){
        printf("Enter the data :");
        scanf("%d",&data);
        root = insertNode(root,data);
    }
    inOrderTraversal(root);
}

/*
Algorithm:

1. **Node Structure (struct node)**:
    - Define a structure for the node that will store:
        - An integer `data` for the node's value.
        - Two pointers `left` and `right` that point to the left and right child nodes of the tree respectively.

2. **Create Node Function (`createNode`)**:
    - Accept an integer `data` as input.
    - Allocate memory for a new node.
    - Initialize the node's `data` field with the input value.
    - Set the `left` and `right` child pointers to NULL (indicating no children).
    - Return the newly created node.

3. **Insert Node Function (`insertNode`)**:
    - Accept the root node (`root`) and a `data` value as input.
    - If the tree is empty (i.e., the root is NULL):
        - Create a new node using `createNode` with the given `data` and return it as the root.
    - If the tree is not empty:
        - Compare the `data` value to the current node's value (`root->data`):
            - If the `data` is less than the current node's value, recursively insert the `data` in the left subtree.
            - If the `data` is greater than the current node's value, recursively insert the `data` in the right subtree.
    - Return the root node (which may have been modified during the insertion process).

4. **In-order Traversal Function (`inOrderTraversal`)**:
    - Accept the root node (`root`) as input.
    - If the root is not NULL, recursively visit the left subtree.
    - Print the current node's `data`.
    - Recursively visit the right subtree.

5. **Main Function (`main`)**:
    - Initialize a pointer `root` to NULL, which will hold the root of the BST.
    - Prompt the user for the number of nodes to insert (`choice`).
    - For each value provided by the user:
        - Insert the value into the tree using `insertNode`.
    - After all nodes are inserted, perform an in-order traversal to print the values in sorted order.

6. **Output**:
    - After the in-order traversal, print the values of the nodes in ascending order, as BSTs store elements such that left children are smaller and right children are larger than the root.
*/
