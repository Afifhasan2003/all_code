#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements (push elements into the queue)
    q.push(10);   // {10}
    q.push(20);   // {10, 20}
    q.push(30);   // {10, 20, 30}

    // Front element (first element in the queue)
    cout << "Front element: " << q.front() << endl; // 10

    // Back element (last element in the queue)
    cout << "Back element: " << q.back() << endl; // 30

    // Dequeue elements (pop elements from the front)
    q.pop(); // Removes 10, now the queue is {20, 30}

    cout << "After pop, front element: " << q.front() << endl; // 20

    // Size of the queue
    cout << "Queue size: " << q.size() << endl; // 2

    // Empty check
    if (q.empty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    // Clearing the queue (pop all elements)
    while (!q.empty()) {
        q.pop();
    }

    cout << "After clearing, queue size: " << q.size() << endl; // 0

    return 0;
}
