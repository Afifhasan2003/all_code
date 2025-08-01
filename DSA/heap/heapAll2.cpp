// here we do the same things but  creating a random complete binary tree

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        left = right = parent = nullptr;
    }
};

// Helper to insert node in level-order to maintain complete binary tree
void insertNode(Node*& root, Node* newNode, int pos, Node* nodes[]) {
    if (pos == 1) {
        root = newNode;
        nodes[1] = newNode;
        return;
    }
    
    int parentPos = pos / 2;
    Node* parent = nodes[parentPos];
    newNode->parent = parent;
    if (pos % 2 == 0)
        parent->left = newNode;
    else
        parent->right = newNode;

    nodes[pos] = newNode;
}

// MAX-HEAPIFY using tree pointers
void maxHeapify(Node* node) {
    if (!node) return;

    Node* largest = node;

    if (node->left && node->left->data > largest->data)
        largest = node->left;
    if (node->right && node->right->data > largest->data)
        largest = node->right;

    if (largest != node) {
        swap(node->data, largest->data);
        maxHeapify(largest);
    }
}

// Build max heap from bottom up
void buildMaxHeap(Node* nodes[], int size) {
    for (int i = size / 2; i >= 1; i--) {
        maxHeapify(nodes[i]);
    }
}

// In-order print for checking
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int arr[] = {4, 10, 3, 5, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = nullptr;
    Node* nodes[100]; // index starts from 1

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        insertNode(root, newNode, i + 1, nodes);
    }

    buildMaxHeap(nodes, n);

    cout << "Inorder after max-heapify: ";
    printInorder(root);
    cout << endl;

    return 0;
}
