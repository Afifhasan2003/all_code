//unordered_but not unique
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;

    // Insert elements (duplicates allowed)
    ms.insert(5);    // {5}
    ms.insert(1);    // {1,5}
    ms.insert(5);    // {1,5,5}
    ms.insert(10);   // {1,5,5,10}
    ms.insert(15);   // {1,5,5,10,15}
    ms.insert(20);   // {1,5,5,10,15,20}
    ms.insert(25);   // {1,5,5,10,15,20,25}

    // Emplace
    ms.emplace(5);   // {1,5,5,5,10,15,20,25}

    // Display multiset
    cout << "Multiset elements:\n";
    for (auto x : ms)
        cout << x << " ";
    cout << endl;

    // Size
    cout << "Size of multiset: " << ms.size() << endl;

    // Find element
    auto it = ms.find(5); // Points to first occurrence of 5
    if (it != ms.end())
        cout << "First 5 found at: " << *it << endl;
    else
        cout << "5 Not found\n";

    // Count how many 5's
    cout << "Count of 5: " << ms.count(5) << endl; // Should be 3

    // Erase ONE occurrence of 5
    if (it != ms.end())
        ms.erase(it); // Erase first 5

    cout << "After erasing one 5:\n";
    for (auto x : ms)
        cout << x << " ";
    cout << endl;

    // Erase ALL 5s
    ms.erase(5); // Erases all remaining 5s

    cout << "After erasing all 5s:\n";
    for (auto x : ms)
        cout << x << " ";
    cout << endl;

    // Insert more elements
    ms.insert({20, 30, 40, 50, 60, 70, 80}); // Adds more values

    // Erase a portion using iterator range BEFORE bound check
    auto it1 = ms.lower_bound(30); // Points to 30
    auto it2 = ms.upper_bound(60); // Points to 70
    // ms.erase(it1, it2); // Erase 30, 40, 50, 60
    
    auto it2 = it1;
    advance(it2, 3); // Move it2 3 positions forward
    ms.erase(it1, it2); // Erase 30, 40, 50 


    cout << "After erasing 30 to 60:\n";
    for (auto x : ms)
        cout << x << " ";
    cout << endl;

    // Lower Bound and Upper Bound
    if (ms.lower_bound(20) != ms.end())
        cout << "Lower bound of 20: " << *ms.lower_bound(20) << endl; // 20
    if (ms.upper_bound(20) != ms.end())
        cout << "Upper bound of 20: " << *ms.upper_bound(20) << endl; // 70

    // Clear
    ms.clear();
    cout << "Size after clear: " << ms.size() << endl;

    return 0;
}
