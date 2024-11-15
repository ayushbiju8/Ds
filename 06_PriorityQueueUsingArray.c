#include <stdio.h>
#define MAX 5

struct priorityQueue{
    int data;
    int priority;
};
int front = -1;
int rear = -1;
struct priorityQueue pq[MAX];

int enqueue(int data,int prio){
    if (front==-1){
        front=0;rear=0;
        pq[front].data=data;
        pq[front].priority=prio;
        return 0;
    }
    if (rear==MAX-1){
        printf("Queue Full \n");
        return -1;
    }
    rear++;
    pq[rear].data=data;
    pq[rear].priority=prio;
    return 0;
}

int dequeue(){
    if (front==-1){
        printf("Queue Empty \n");
        return 0;
    }
    if (front==rear){
        printf("Dequeued Element : %d \n",pq[front].data);
        front=-1;rear=-1;
        return 0;
    }
    int highestPrio = front;
    for (int i=front;i<=rear;i++){
        if(pq[i].priority < pq[highestPrio].priority){
            highestPrio = i;
        } 
    }
    for (int i= highestPrio;i<=rear;i++){
        pq[i]= pq[i+1];
    }
    rear--;
    return 0;
}

int display(){
    if (front==-1){
        printf("Queue Empty \n");
        return 0;
    }
    for(int i=front;i<=rear;i++){
        printf(" %d(%d)\n",pq[i].data,pq[i].priority);
    }
    return 0;
}

int main(){
    while (1){
        int choice, temp,temp2;
        printf("MENU\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        scanf("%d", &choice);
        if (choice == 1){
            printf("Enter the no to push : ");
            scanf("%d", &temp);
            printf("Enter the priority : ");
            scanf("%d", &temp2);
            enqueue(temp,temp2);
        }else if (choice == 2){
            dequeue();
        }else if (choice == 3){
            display();
        }else{
            break;
        }
    }
}


// Include standard input-output library and define MAX constant for priority queue size

// Define a structure 'priorityQueue' to store data elements along with their priorities
// Initialize 'front' and 'rear' to -1, indicating an empty queue
// Declare 'pq' array of type 'priorityQueue' to represent the priority queue

// Function to enqueue (add) an element with priority to the priority queue
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, initialize 'front' and 'rear' to 0 and insert the element at the front
// Step 2: Check if the queue is full (rear == MAX - 1)
//         - If full, print "Queue Full" and return -1
// Step 3: If not full, increment 'rear' and insert the element at 'rear' with its priority

// Function to dequeue (remove) an element with the highest priority from the priority queue
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, print "Queue Empty" and return 0
// Step 2: Check if there is only one element (front == rear)
//         - If true, print and remove the element, then reset front and rear to -1
// Step 3: Find the element with the highest priority (lowest priority value) in the queue
// Step 4: Shift elements after the highest priority element to fill the gap
// Step 5: Decrement 'rear' after removing the highest priority element

// Function to display all elements in the priority queue with their priorities
// Step 1: Check if the queue is empty (front == -1)
//         - If empty, print "Queue Empty" and return 0
// Step 2: If not empty, iterate from 'front' to 'rear' and print each element along with its priority

// Main function to manage priority queue operations with a menu
// Step 1: Display a menu with options to enqueue, dequeue, display, and exit
// Step 2: Based on user's choice, call the corresponding function
// Step 3: If choice is enqueue, prompt user for a data element and its priority
// Step 4: If choice is exit, break the loop to end the program
