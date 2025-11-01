#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

Node* heap[MAX];
int heapSize = 0;

// Index helpers
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// Create Node
Node* createNode(int data) {
    Node* node = new Node{data, nullptr, nullptr, nullptr};  // automatically initialize left, right, and parent to nullptr
    return node;
}

// Link children and parent
void link(Node* parent, Node* child, bool isLeft) {
    if (child) child->parent = parent;
    if (isLeft) parent->left = child;
    else parent->right = child;
}

// Build binary tree from array
void buildTree(int arr[], int n) {
    for (int i = 0; i < n; i++)
        heap[i] = createNode(arr[i]);           // nodes created, but not linked yet
    heapSize = n;

            //this part is used only if the array is representing a complete binary tree at the first place
            //if we were to make a random complete binary tree, we would need to link nodes differently (shown in heapAll2.cpp)

    for (int i = 0; i < n; i++) {               //forming a complete binary tree
        int l = left(i);
        int r = right(i);
        if (l < n) link(heap[i], heap[l], true);
        if (r < n) link(heap[i], heap[r], false);
    }
}

// MAX-HEAPIFY      //In maxHeapify, the smaller values slide down because:
void maxHeapify(int i) {    // i is root of subtree
    int l = left(i), r = right(i), largest = i;

    if (l < heapSize && heap[l]->data > heap[largest]->data)
        largest = l;
    if (r < heapSize && heap[r]->data > heap[largest]->data)
        largest = r;

    if (largest != i) {
        swap(heap[i]->data, heap[largest]->data);
        maxHeapify(largest);    //data inside largest is changed, but the pointers remain to one of the children
    }
}

void minHeapify(int i) {
    int l = left(i), r = right(i), smallest = i;

    if (l < heapSize && heap[l]->data < heap[smallest]->data)
        smallest = l;
    if (r < heapSize && heap[r]->data < heap[smallest]->data)
        smallest = r;

    if (smallest != i) {
        swap(heap[i]->data, heap[smallest]->data);
        minHeapify(smallest);
    }
}


// BUILD-MAX-HEAP
void buildMaxHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        maxHeapify(i);
}


// BUILD-MIN-HEAP
void buildMinHeap() {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        minHeapify(i);
}

// HEAPSORT (big to small)
void heapSort() {
    buildMaxHeap();
    int originalSize = heapSize;

    for (int i = heapSize - 1; i >= 1; i--) {
        swap(heap[0]->data, heap[i]->data);
        heapSize--;
        maxHeapify(0);
    }

    heapSize = originalSize;
}

// HEAPSORT (small to big)
void heapSortMin() {
    buildMinHeap();
    int originalSize = heapSize;

    for (int i = heapSize - 1; i >= 1; i--) {
        swap(heap[0]->data, heap[i]->data);
        heapSize--;
        minHeapify(0);
    }

    heapSize = originalSize;
}


// EXTRACT-MAX
int extractMax() {
    if (heapSize < 1) return -1;
    int maxVal = heap[0]->data;
    heap[0]->data = heap[heapSize - 1]->data;
    heapSize--;
    maxHeapify(0);
    return maxVal;
}
// EXTRACT-MIN
int extractMin() {
    if (heapSize < 1) return -1;
    int minVal = heap[0]->data;
    heap[0]->data = heap[heapSize - 1]->data;
    heapSize--;
    minHeapify(0);
    return minVal;
}

// HEAP-INCREASE-KEY
void heapIncreaseKey(int i, int newKey) {       // i is index of the node to increase, newKey is the new value
    if (newKey < heap[i]->data) return;

    heap[i]->data = newKey;
    while (i > 0 && heap[parent(i)]->data < heap[i]->data) {
        swap(heap[i]->data, heap[parent(i)]->data);
        i = parent(i);
    }
}


// INSERT
void insert(int key) {
    if (heapSize >= MAX) return;

    Node* node = createNode(-1e9); // -∞
    heap[heapSize] = node;
    int i = heapSize++;
    heapIncreaseKey(i, key);

    if (i != 0) {
        int p = parent(i);
        if (i == left(p)) link(heap[p], heap[i], true);
        else link(heap[p], heap[i], false);
    }
}


void printHeap() {
    for (int i = 0; i < heapSize; i++)
        cout << heap[i]->data << " ";
    cout << endl;
}


int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildTree(arr, n);
    buildMaxHeap();

    cout << "Max Heap: ";
    printHeap();

    cout << "After inserting 15: ";
    insert(15);
    printHeap();

    cout << "After extractMax(): ";
    extractMax();
    printHeap();

    cout << "After increasing index 2 to 20: ";
    heapIncreaseKey(2, 20);
    printHeap();

    cout << "After HeapSort: ";
    heapSort();
    printHeap();        // 1 4 5 10 20

    return 0;
}
 