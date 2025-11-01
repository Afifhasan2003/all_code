#include <iostream>
#include <queue>
using namespace std;



void defaultProperty() {
    priority_queue<int> pq;  //dont need to specify underlying container and comparator, by default it is max-heap
    pq.push(10);  
    pq.push(30);  
    pq.push(20);  
    pq.push(50);  // {50, 30, 20, 10}

    cout << "Top element: " << pq.top() << endl;  // 50

    pq.pop();  // Removes 50, now the heap is {30, 10, 20}
    cout << "After pop, top element: " << pq.top() << endl;  // 30

    cout << "Size: " << pq.size() << endl;  // 3

    if (pq.empty())
        cout << "Priority queue is empty\n";
    else
        cout << "Priority queue is not empty\n";
}

void minPriority_AtTop() {
    priority_queue<int, vector<int>, greater<int>> mpq;  //vector<int> is the underlying container,
    mpq.push(10);  
    mpq.push(30);  
    mpq.push(20);  
    mpq.push(5);   // {5, 10, 20, 30}

    cout << "Top element: " << mpq.top() << endl;  // 5

    mpq.pop();  // Removes 5, now the heap is {10, 30, 20}
    cout << "After pop, top element: " << mpq.top() << endl;  // 10

    cout << "Size: " << mpq.size() << endl;  // 3

    if (mpq.empty())
        cout << "Min-Heap is empty\n";
    else
        cout << "Min-Heap is not empty\n";
}

void pairsInPriorityQueue() {
    priority_queue<pair<int, int>> pq;  //max-heap based on first element of pair
    pq.push({1, 2});  
    pq.push({2, 3});  
    pq.push({0, 4});  
    pq.push({2, 1});   // {(2,3), (2,1), (1,2), (0,4)}


    
}

int main() {
   



    
 

    return 0;
}
