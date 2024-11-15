#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// struct node* root=NULL;


struct node* createNode(int data){
    struct node *newnode= (struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insertBinaryNode(){
    int data;
    int c;
    printf("Enter the data :");
    scanf("%d",&data);
    struct node* root = createNode(data);
    printf("Does the node have left child (1/0) :");
    scanf(" %d",&c);
    if (c==1){
        root->left = insertBinaryNode();
    }
    printf("Does the node have right child (1/0) :");
    scanf(" %d",&c);
    if (c==1){
        root->right  = insertBinaryNode();
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
    struct node* root = insertBinaryNode();
    inOrderTraversal(root);
}

// Algorithm to insert nodes into a binary tree and perform in-order traversal:
//
// 1. Define a structure `struct node` to represent each node in the binary tree.
//    - `int data`: This will store the value/data for each node in the tree.
//    - `struct node* left`: A pointer to the left child of the node.
//    - `struct node* right`: A pointer to the right child of the node.
//
// 2. Define a function `createNode` to create a new binary tree node:
//    - Allocate memory for a new node using `malloc`.
//    - Set the `data` of the node to the provided value.
//    - Set the `left` and `right` child pointers of the node to `NULL` since it’s a new node without children.
//    - Return the pointer to the newly created node.
//
// 3. Define a function `insertBinaryNode` to insert nodes into the binary tree:
//    - Ask the user to enter the `data` for the node (value to be stored).
//    - Call the `createNode` function to create a node with the entered data.
//    - Ask the user whether the current node should have a left child:
//        - If `yes` (enter 1), recursively call `insertBinaryNode` to insert the left child of the current node.
//    - Ask the user whether the current node should have a right child:
//        - If `yes` (enter 1), recursively call `insertBinaryNode` to insert the right child of the current node.
//    - Once the left and right children (if any) are added, return the current node, which will be the root of this subtree.
//
// 4. Define a function `inOrderTraversal` to traverse the binary tree in in-order:
//    - If the current node is `NULL`, simply return (end the traversal).
//    - Recursively call `inOrderTraversal` for the left child to visit all left descendants first.
//    - Print the `data` of the current node (root of the current subtree).
//    - Recursively call `inOrderTraversal` for the right child to visit all right descendants after the current node.
//
// 5. In the `main` function:
//    - Declare a pointer `struct node* root` to store the root of the binary tree.
//    - Call the `insertBinaryNode` function to begin constructing the binary tree from user input.
//    - Call the `inOrderTraversal` function, passing the `root`, to perform an in-order traversal of the tree and print the node values in in-order sequence.
//
// 6. Result:
//    - The program will prompt the user to enter data for each node and decide whether that node should have left and right children.
//    - The in-order traversal will visit all left children first, followed by the current node, and then the right children.
//
// 7. Example of an in-order traversal of a binary tree:
//    - For a binary tree like this:
//      ```
//            1
//           / \
//          2   3
//         / \
//        4   5
//      ```
//    - The in-order traversal will print: `4 2 5 1 3`