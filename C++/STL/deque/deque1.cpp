// very similar to vector + list 
// from chatgpt
#include <iostream>
#include <deque>
#include <algorithm> // for sort() and reverse()
using namespace std;

int main() {
    deque<int> d;

    // Insert elements
    d.push_back(10);      // {10}
    d.push_front(20);     // {20,10}
    d.emplace_back(30);   // {20,10,30}
    d.emplace_front(40);  // {40,20,10,30}

    // Display deque
    cout << "Deque elements:\n";
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // Remove elements
    d.pop_back();         // {40,20,10}
    d.pop_front();        // {20,10}

    cout << "After pop operations:\n";
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // Insert at specific position
    auto it = d.begin();
    it++;
    d.insert(it, 25);         // {20,25,10} insert 25 before 10
    d.insert(it, 2, 15);      // {20,15,15,25,10} insert 2 times 15 before 25
    d.insert(d.end(), 5, 50); // {20,15,15,25,10,50,50,50,50,50} insert 5 times 50 at the end
    d.insert(d.begin(), {1, 2, 3}); // {1,2,3,20,15,15,25,10,50,50,50,50,50}

    // Erase at specific position
    it = d.begin();
    d.erase(it); // erase first element {2,3,20,15,15,25,10,50,50,50,50,50}

    cout << "After insert and erase:\n";
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // Access front and back
    cout << "Front: " << d.front() << ", Back: " << d.back() << endl;

    // Size
    cout << "Size of deque: " << d.size() << endl;

    // Sort deque
    sort(d.begin(), d.end()); // need <algorithm> header if outside simple examples


    cout << "Sorted deque:\n";
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // descending order
    reverse(d.begin(), d.end());

    cout << "Descending order deque:\n";
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    // Clear deque
    d.clear();
    cout << "Size after clear: " << d.size() << endl;

    return 0;
}
