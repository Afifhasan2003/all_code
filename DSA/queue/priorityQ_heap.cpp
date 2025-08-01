#include <iostream>
using namespace std;

#define SIZE 100

int maxHeap[SIZE];
int minHeap[SIZE];
int maxSize = 0;
int minSize = 0;

// MAX HEAPIFY: heapify downward from index i
void maxHeapify(int arr[], int size, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < size && arr[l] > arr[largest]) largest = l;
    if(r < size && arr[r] > arr[largest]) largest = r;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

// BUILD MAX HEAP
void buildMaxHeap(int arr[], int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

// INSERT into max-heap
void insertMax(int val) {
    if(maxSize == SIZE) {
        cout << "Max Heap Overflow\n";
        return;
    }
    maxHeap[maxSize] = val;
    int i = maxSize;
    maxSize++;

    // Move up to maintain heap
    while(i != 0 && maxHeap[(i-1)/2] < maxHeap[i]) {
        swap(maxHeap[i], maxHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// DELETE max (root)
void deleteMax() {
    if(maxSize == 0) {
        cout << "Max Heap Underflow\n";
        return;
    }
    cout << "Deleted Max: " << maxHeap[0] << endl;
    maxHeap[0] = maxHeap[maxSize - 1];
    maxSize--;
    maxHeapify(maxHeap, maxSize, 0);
}

// MIN HEAPIFY: heapify downward from index i
void minHeapify(int arr[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < size && arr[l] < arr[smallest]) smallest = l;
    if(r < size && arr[r] < arr[smallest]) smallest = r;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

// BUILD MIN HEAP
void buildMinHeap(int arr[], int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        minHeapify(arr, size, i);
    }
}

// INSERT into min-heap
void insertMin(int val) {
    if(minSize == SIZE) {
        cout << "Min Heap Overflow\n";
        return;
    }
    minHeap[minSize] = val;
    int i = minSize;
    minSize++;

    // Move up to maintain heap
    while(i != 0 && minHeap[(i-1)/2] > minHeap[i]) {
        swap(minHeap[i], minHeap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// DELETE min (root)
void deleteMin() {
    if(minSize == 0) {
        cout << "Min Heap Underflow\n";
        return;
    }
    cout << "Deleted Min: " << minHeap[0] << endl;
    minHeap[0] = minHeap[minSize - 1];
    minSize--;
    minHeapify(minHeap, minSize, 0);
}

// Display Heap
void displayHeap(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int values[] = {30, 10, 50, 20, 40};
    int n = 5;

    // Build max heap
    for(int i = 0; i < n; i++) insertMax(values[i]);
    cout << "--- Max Heap (Descending Priority) ---\n";
    displayHeap(maxHeap, maxSize);
    deleteMax();
    displayHeap(maxHeap, maxSize);

    // Build min heap
    for(int i = 0; i < n; i++) insertMin(values[i]);
    cout << "\n--- Min Heap (Ascending Priority) ---\n";
    displayHeap(minHeap, minSize);
    deleteMin();
    displayHeap(minHeap, minSize);

    return 0;
}
