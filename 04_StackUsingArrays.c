#include <stdio.h>
#define MAX 10

int stack[MAX];
int top=-1;

int push(int x){
    if (top== (MAX-1)){
        printf("Stack OverFlow\n");
        return -1;
    }
    top++;
    stack[top]=x;
}

int pop(){
    if (top==-1){
        printf("Stack UnderFlow\n");
        return -1;
    }
    printf("Popped Element : %d \n",stack[top]);
    top--;
}

int peek(){
    if (top==-1){
        printf("Stack UnderFlow\n");
        return -1;
    }
    printf("Top Element : %d \n",stack[top]);
}

int display(){
    if (top==-1){
        printf("Stack UnderFlow\n");
        return -1;
    }
    for(int i=0;i<=top;i++){
        printf(" %d \n",stack[i]);
    }
}


int main(){
    while(1){
        int choice,temp;
        printf("MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        scanf("%d",&choice);
        if (choice==1){
            printf("Enter the no to push : ");
            scanf("%d",&temp);
            push(temp);
        }else if(choice==2){
            pop();
        }else if(choice==3){
            peek();
        }
        else if(choice==4){
            display();
        }else{
            break;
        }
    }
}

// Include standard input-output library and define a constant MAX for stack size

// Declare stack array to hold elements and initialize 'top' to -1, representing an empty stack

// Function to push an element onto the stack
// Step 1: Check if the stack is full (top == MAX - 1)
// Step 2: If full, print "Stack Overflow" and return -1
// Step 3: If not full, increment 'top' and add the element to the stack

// Function to pop an element from the stack
// Step 1: Check if the stack is empty (top == -1)
// Step 2: If empty, print "Stack Underflow" and return -1
// Step 3: If not empty, print the top element and decrement 'top'

// Function to peek at the top element without removing it
// Step 1: Check if the stack is empty (top == -1)
// Step 2: If empty, print "Stack Underflow" and return -1
// Step 3: If not empty, print the top element

// Function to display all elements in the stack
// Step 1: Check if the stack is empty (top == -1)
// Step 2: If empty, print "Stack Underflow" and return -1
// Step 3: If not empty, iterate from the bottom to the top and print each element

// Main function for stack operations menu
// Step 1: Display a menu with options for push, pop, peek, display, and exit
// Step 2: Based on user's choice, call the corresponding function
// Step 3: If choice is push, prompt user for an element to add to the stack
// Step 4: If choice is exit, break the loop to end the program
