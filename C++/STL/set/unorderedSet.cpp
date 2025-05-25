//unique but unordered
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us; // Create unordered_set

    // Insert elements
    us.insert(10);    // {10}
    us.insert(20);    // {10,20}
    us.insert(30);    // {10,20,30}
    us.insert(40);    // {10,20,30,40}

    // Emplace element
    us.emplace(50);   // {10,20,30,40,50}

    // Try inserting duplicate (won't be added)
    us.insert(20);    // {10,20,30,40,50} no duplicate allowed

    // Display elements
    cout << "Unordered Set elements:\n";
    for (auto x : us)
        cout << x << " ";
    cout << endl;

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
