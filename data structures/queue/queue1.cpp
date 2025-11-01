#include <iostream>
using namespace std;

#define SIZE 100

// Simple Queue
int queue[SIZE];
int front = -1, rear = -1;

// Circular Queue
int cqueue[SIZE];
int cfront = -1, crear = -1;

// Function to add array values to a simple queue
void enqueueFromArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(rear == SIZE - 1) {
            cout << "Queue overflow\n";
            return;
        }
        if(front == -1) front = 0;
        rear++;
        queue[rear] = arr[i];
    }
}

// Function to insert a value in simple queue
void enqueue(int val) {
    if(rear == SIZE - 1) {
        cout << "Queue overflow\n";
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = val;
}

// Function to delete a value from simple queue
void dequeue() {
    if(front == -1 || front > rear) {
        cout << "Queue underflow\n";
        return;
    }
    cout << "Deleted: " << queue[front] << endl;
    front++;
}

// Function to print simple queue
void printQueue() {
    if(front == -1 || front > rear) {
        cout << "Simple queue is empty\n";
        return;
    }
    cout << "Simple Queue: ";
    for(int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Circular Queue insert
void circularEnqueue(int val) {
    // If full: either front = 0 and rear = SIZE - 1 or rear + 1 == front
    if((cfront == 0 && crear == SIZE - 1) || (crear + 1) % SIZE == cfront) {   //  (crear + 1) % SIZE == 0 when crear == SIZE - 1
        cout << "Circular queue overflow\n";
        return;
    }
    if(cfront == -1) cfront = 0;

    // if(crear == SIZE - 1) {
    //     crear = 0; // wrap around
    // } else {
    //     crear++;
    // }
    crear = (crear + 1) % SIZE;

    cqueue[crear] = val;
}

// Circular Queue delete
void circularDequeue() {
    if(cfront == -1) {
        cout << "Circular queue underflow\n";
        return;
    }
    cout << "Deleted: " << cqueue[cfront] << endl;
    if(cfront == crear) {
        // Only one element was there
        cfront = crear = -1;
    } else {
        cfront = (cfront + 1) % SIZE;
    }
}

// Function to print circular queue
void printCircularQueue() {
    if(cfront == -1) {
        cout << "Circular queue is empty\n";
        return;
    }
    cout << "Circular Queue: ";
    int i = cfront;
    do {
        cout << cqueue[i] << " ";
        i = (i + 1) % SIZE;
    } while(i != (crear + 1) % SIZE);
    cout << endl;
}

// Function to add array values to circular queue
void circularEnqueueFromArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        circularEnqueue(arr[i]);
    }
}

int main() {
    // Sample usage:
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;

   
    enqueueFromArray(arr, n);
    printQueue();
    
    cout << "\nAdding element 60...\n";
    enqueue(60);
    printQueue();
    
    cout << "\nDequeuing elements...\n";
    dequeue();
    printQueue();
    dequeue();
    printQueue();

    cout << "\n=================================\n";
    cout << "\n--- Circular Queue ---\n";
  
    circularEnqueueFromArray(arr, n);
    printCircularQueue();
    
    cout << "\nAdding element 60...\n";
    circularEnqueue(60);
    printCircularQueue();
    
    cout << "\nDequeuing elements...\n";
    circularDequeue();
    printCircularQueue();
    circularDequeue();
    printCircularQueue();

   

    return 0;
}
