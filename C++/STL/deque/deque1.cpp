// very similar to vector + list 
// from chatgpt
#include <iostream>
#include <deque>
#include <algorithm> // for sort() and reverse()
using namespace std;

void display(const deque<int>& d) {
    //yes, we can iterate on deque, but not on queue.
    for (auto elem : d) {
        cout << elem << " ";
    }
    cout << endl;
}

void insertProperty(deque<int>& d) {

    d.clear();
    d.push_back(10);
    d.push_front(20);       // now d = {20,10}

    auto it = d.begin();        
    it++;                       // point to second element (10)
    d.insert(it, 25);         // {20,25,10} insert 25 before 10
    d.insert(it, 2, 15);      // {20,15,15,25,10} insert 2 times 15 before 25
    d.insert(d.end(), 5, 50); // {20,15,15,25,10,50,50,50,50,50} insert 5 times 50 at the end
    d.insert(d.begin(), {1, 2, 3}); // {1,2,3,20,15,15,25,10,50,50,50,50,50}
}

void insert_at_position(deque<int>& d, int position, int value) {
    if (position < 0 || position > d.size()) {
        cout << "Invalid position!" << endl;
        return;
    }
    auto it = d.begin() + position;
    d.insert(it, value);

    //if d = {10,20,30} and position = 1, value = 15
    //then d = {10,15,20,30}
}

void removeALLOccurance(deque<int>& d, int value) {
    d.erase(remove(d.begin(), d.end(), value), d.end());
    //remove all occurrences of value from deque
}
void removeOnceByvalue(deque<int>& d, int value) {
    auto it = find(d.begin(), d.end(), value);
    if (it != d.end()) {
        d.erase(it);
    }
    //remove first occurrence of value from deque
}

int main() {
    deque<int> d;

    // Insert elements
    d.push_back(10);      // {10}
    d.push_front(20);     // {20,10}
    d.push_back(30);      // {20,10,30}
    d.push_front(40);     // {40,20,10,30}
    d.push_back(50);      // {40,20,10,30,50}
    d.push_back(60);      // {40,20,10,30,50,60}
    d.emplace_front(70);  // {70,40,20,10,30,50,60}

    cout << "After push and emplace operations:\n";
    display(d);

    // Remove elements
    d.pop_back();         // {70,40,20,10,30,50,60}
    d.pop_front();        // {40,20,10,30,50,60}

    cout << "After pop operations:\n";
    display(d);

    // Insert at specific position
    

    // Erase at specific position
    auto it = d.begin();
    d.erase(it); // erase first element {2,3,20,15,15,25,10,50,50,50,50,50}

    cout << "After insert and erase:\n";
    display(d);
    cout << endl;

    // Access front and back
    cout << "Front: " << d.front() << ", Back: " << d.back() << endl;

    // Size
    cout << "Size of deque: " << d.size() << endl;

    // Sort deque
    sort(d.begin(), d.end()); // need <algorithm> header if outside simple examples


    cout << "Sorted deque:\n";
    display(d);

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
