#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max-Heap (default priority_queue behavior)
    priority_queue<int> maxHeap;

    // Insert elements
    maxHeap.push(10);  // {10}
    maxHeap.push(30);  // {30, 10}
    maxHeap.push(20);  // {30, 10, 20} not sorted, but max-heap property maintained
    maxHeap.push(50);  // {50, 30, 20, 10}

    cout << "Max-Heap (Top element): " << maxHeap.top() << endl;  // 50

    // Pop the top element
    maxHeap.pop();  // Removes 50, now the heap is {30, 10, 20}
    cout << "After pop, Max-Heap top element: " << maxHeap.top() << endl;  // 30

    // Check size of the Max-Heap
    cout << "Max-Heap size: " << maxHeap.size() << endl;  // 3

    // Check if the Max-Heap is empty
    if (maxHeap.empty())
        cout << "Max-Heap is empty\n";
    else
        cout << "Max-Heap is not empty\n";

    // Min-Heap (using greater<int> to customize)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements
    minHeap.push(10);  // {10}
    minHeap.push(30);  // {10, 30}
    minHeap.push(20);  // {10, 30, 20}
    minHeap.push(5);   // {5, 10, 20, 30}

    cout << "\nMin-Heap (Top element): " << minHeap.top() << endl;  // 5

    // Pop the top element
    minHeap.pop();  // Removes 5, now the heap is {10, 30, 20}
    cout << "After pop, Min-Heap top element: " << minHeap.top() << endl;  // 10

    // Check size of the Min-Heap
    cout << "Min-Heap size: " << minHeap.size() << endl;  // 3

    // Check if the Min-Heap is empty
    if (minHeap.empty())
        cout << "Min-Heap is empty\n";
    else
        cout << "Min-Heap is not empty\n";

    // Clearing the Max-Heap and Min-Heap
    while (!maxHeap.empty()) {
        maxHeap.pop();
    }
    cout << "\nAfter clearing Max-Heap, size: " << maxHeap.size() << endl;  // 0

    while (!minHeap.empty()) {
        minHeap.pop();
    }
    cout << "After clearing Min-Heap, size: " << minHeap.size() << endl;  // 0

    return 0;
}
