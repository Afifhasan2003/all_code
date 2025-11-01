//very similar to vector
#include <iostream>
#include <list>
using namespace std;

void properties(){
    // list is a doubly linked list
    //can push and pop from both ends in O(1) time
    //insertion and deletion in middle is O(1) if we have the iterator to that position
    //no random access, no operator[]
}



int main() {
    list<int> l;

    // Insert elements
    l.push_back(10);      //{10}
    l.push_front(20);     //{20,10}
    l.emplace_back(30);   //{20,10,30}
    l.emplace_front(40); //{40,20,10,30}

    // Display list
    cout << "List elements:\n";
    for (auto x : l)
        cout << x << " ";
    cout << endl;

    // Remove elements
    l.pop_back();        //{40,20,10}
    l.pop_front();      //{20,10}

    cout << "After pop operations:\n";
    for (auto x : l)
        cout << x << " ";
    cout << endl;

    // Insert at specific position
    auto it = l.begin();
    int pos = 2;
    advance(it, pos);
    l.insert(it, 25); // {20,25,10}  insert 25 before 10
    l.insert(it, 2, 15); // {20,15,15,25,10} insert 2 times 15 before 25
    l.insert(l.end(), 5, 50); // {20,15,15,25,10,50,50,50,50,50} insert 5 times 50 at the end
    l.insert(l.begin(), {1, 2, 3}); // {1,2,3,20,15,15,25,10,50,50,50,50,50} insert 1,2,3 at the beginning

    // Erase at specific position
    pos = 4;
    advance(it, pos);
    l.erase(it); // erase first element {2,3,20,15,15,25,10,50,50,50,50}

    cout << "After insert and erase:\n";
    for (auto x : l)
        cout << x << " ";
    cout << endl;

    // Size
    cout << "Size of list: " << l.size() << endl;

    // Reverse list
    l.reverse();
    cout << "Reversed list:\n";
    for (auto x : l)
        cout << x << " ";
    cout << endl;

    // Sort list
    l.sort();
    
    cout << "Sorted list:\n";
    for (auto x : l)
        cout << x << " ";
    cout << endl;

    // descending order
    l.reverse();

    // Clear list
    l.clear();
    cout << "Size after clear: " << l.size() << endl;

    return 0;
}
