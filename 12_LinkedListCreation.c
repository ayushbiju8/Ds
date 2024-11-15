#include <stdio.h>
#include <stdlib.h>

struct node * root = NULL;
struct node * temp = NULL;

struct node{
    int data;
    struct node * next;
};

struct node * createNode(int data){
    struct node * newnode =(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertNode(int data){
    if (root == NULL){
        root = createNode(data);
        return;
    }
    struct node* new = createNode(data);
    temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
}

void traverseNode(){
    temp = root;
    while (temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void reverseNode(){
    struct node * prev=NULL;
    struct node * current=root;
    struct node * next=NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    root = prev;
}

int main(){
    // insertNode(1);
    insertNode(100);
    insertNode(110);
    insertNode(100);
    insertNode(150);
    traverseNode();
    reverseNode();
    traverseNode();
}