#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

Node* head = NULL;

// Function to create a new node
Node* createNode(int val, int pri) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->priority = pri;
    newNode->next = NULL;
    return newNode;
}


// values are at top when pri is higher
void insert(int val, int pri) {
    Node* newNode = createNode(val, pri);

    // If empty or highest priority
    if(head == NULL || pri > head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to find correct position
    Node* prev = head;
    Node* curr = head->next;
    while(curr != NULL && curr->priority >= pri) {
        prev = curr;
        curr = curr->next;
    }

    // Insert between prev and curr
    prev->next = newNode;
    newNode->next = curr;
}

// Delete highest priority element (at head)
void remove() {
    if(head == NULL) {
        cout << "Underflow: Queue is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << " (priority " << temp->priority << ")\n";
    delete temp;
}

// Display all elements
void display() {
    if(head == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout  << temp->data <<" ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 3);
    insert(40, 5);
    display();

    remove();
    display();

    return 0;
}
