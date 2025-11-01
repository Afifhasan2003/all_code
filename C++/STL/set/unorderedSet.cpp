//unique but unordered
#include <iostream>
#include <unordered_set>
using namespace std;

void display(const unordered_set<int>& us) {
    cout << "Unordered Set elements:\n";
    for (auto x : us)
        cout << x << " ";
    cout << endl;

    // Note: we cannot predict the order of elements in unordered_set
}

int main() {
    unordered_set<int> us; // Create unordered_set


    us.insert(10);    // {10}
    us.insert(20);    // {10,20}
    us.insert(30);    // {10,20,30}
    us.insert(40);    // {10,20,30,40}

    // Emplace is better
    us.emplace(50);   // {10,20,30,40,50}

    us.insert(20);    // {10,20,30,40,50} no duplicate allowed

    display(us); 

    // Size
    cout << "Size of unordered_set: " << us.size() << endl;

    // Find an element
    if (us.find(30) != us.end())
        cout << "30 is found\n";
    else
        cout << "30 not found\n";

    // Erase an element
    us.erase(20); // Remove 20 if it exists

    cout << "After erasing 20:\n";
    for (auto x : us)
        cout << x << " ";
    cout << endl;

    // Count (returns 0 or 1 in unordered_set)
    cout << "Count of 10: " << us.count(10) << endl;

    // Clear the unordered_set
    us.clear(); // Removes all elements

    // Final size
    cout << "Size after clear: " << us.size() << endl;

    return 0;
}
