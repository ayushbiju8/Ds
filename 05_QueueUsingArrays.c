#include <stdio.h>
#define MAX 5

int front = -1;
int rear = -1;
int queue[MAX];

int enqueue(int data){
    if (front==-1){
        front=0;rear=0;
        queue[front]=data;
        return 0;
    }
    if (rear==MAX-1){
        printf("Queue Full \n");
        return -1;
    }
    rear++;
    queue[rear]=data;
    return 0;
}

int dequeue(){
    if (front==-1){
        printf("Queue Empty \n");
        return 0;
    }
    if (front==rear){
        printf("Dequeued Element : %d \n",queue[front]);
        front=-1;rear=-1;
        return 0;
    }
    printf("Dequeued Element : %d \n",queue[front]);
    front++;
    return 0;
}

int display(){
    if (front==-1){
        printf("Queue Empty \n");
        return 0;
    }
    for(int i=front;i<=rear;i++){
        printf(" %d \n",queue[i]);
    }
    return 0;
}

int main(){
    while (1){
        int choice, temp;
        printf("MENU\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        scanf("%d", &choice);
        if (choice == 1){
            printf("Enter the no to push : ");
            scanf("%d", &temp);
            enqueue(temp);
        }else if (choice == 2){
            dequeue();
        }else if (choice == 3){
            display();
        }else{
            break;
        }
    }
}


// Include standard input-output library and define MAX constant for queue size

// Initialize 'front' and 'rear' to -1, indicating an empty queue
// Declare 'queue' array to store elements

// Function to enqueue (add) an element to the queue
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, set 'front' and 'rear' to 0 and insert the element at the front
// Step 2: Check if the queue is full (rear == MAX - 1)
//         - If full, print "Queue Full" and return -1
// Step 3: If not full, increment 'rear' and insert the element at 'rear' position

// Function to dequeue (remove) an element from the queue
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, print "Queue Empty" and return 0
// Step 2: Check if there is only one element (front == rear)
//         - If true, print and remove the element, then reset front and rear to -1
// Step 3: Otherwise, print and remove the element at 'front' and increment 'front'

// Function to display all elements in the queue
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, print "Queue Empty" and return 0
// Step 2: If not empty, iterate from 'front' to 'rear' and print each element

// Main function for queue operations menu
// Step 1: Display a menu with options to enqueue, dequeue, display, and exit
// Step 2: Based on user's choice, call the corresponding function
// Step 3: If choice is enqueue, prompt user for an element to add to the queue
// Step 4: If choice is exit, break the loop to end the program
