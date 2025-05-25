#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_multiset<int> ums; // Create unordered_multiset

    // Insert elements (duplicates allowed)
    ums.insert(10);    // {10}
    ums.insert(20);    // {10,20}
    ums.insert(10);    // {10,10,20}
    ums.insert(30);    // {10,10,20,30}

    // Emplace element
    ums.emplace(20);   // {10,10,20,20,30}

    // Display elements
    cout << "Unordered Multiset elements:\n";
    for (auto x : ums)
        cout << x << " ";
    cout << endl;

    // Size
    cout << "Size of unordered_multiset: " << ums.size() << endl;

    // Count occurrences of an element
    cout << "Count of 10: " << ums.count(10) << endl; // 2

    // Find an element
    auto it = ums.find(20); // Points to one occurrence of 20
    if (it != ums.end())
        cout << "20 is found: " << *it << endl;
    else
        cout << "20 not found\n";

    // Erase one occurrence of 20
    if (it != ums.end())
        ums.erase(it); // Removes one 20

    cout << "After erasing one 20:\n";
    for (auto x : ums)
        cout << x << " ";
    cout << endl;

    // Erase all occurrences of 10
    ums.erase(10); // Removes all 10s

    cout << "After erasing all 10s:\n";
    for (auto x : ums)
        cout << x << " ";
    cout << endl;

    // Clear the unordered_multiset
    ums.clear();

    // Final size
    cout << "Size after clear: " << ums.size() << endl;

    return 0;
}
