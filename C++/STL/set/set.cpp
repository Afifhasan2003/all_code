//set is sorted and unique
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Insert elements
    s.insert(5);   // {5}
    s.insert(1);   // {1,5}
    s.insert(10);  // {1,5,10}
    s.insert(5);   // {1,5,10}  (no duplicate allowed)
    
    s.insert(2);   // {1,2,5,10}
    s.insert(3);   // {1,2,3,5,10}
    s.insert(4);   // {1,2,3,4,5,10}
    // Emplace (faster than insert sometimes)
    s.emplace(7);  // {1,2,3,4,5,7,10}

    // Display set
    cout << "Set elements:\n";
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    // Size
    cout << "Size of set: " << s.size() << endl;

    // Find an element 
    if (s.find(5) != s.end())           //s.find(5) returns an pointer to the element if found, else points to the memory after the last element
        cout << "5 Found!\n";
    else
        cout << "5 Not found!\n";

    if (s.find(20) != s.end())          //s.end() returns an pointer to the memory after the last element of the set
        cout << "20 Found!\n";
    else
        cout << "20 Not found!\n";

    // Erase an element
    s.erase(5); // {1,2,3,4,7,10}  (5 is removed)
    cout << "After erasing 5:\n";
    for (auto x : s)
        cout << x << " ";
    cout << endl;

    // Erase by iterator
    auto it = s.begin();
    s.erase(it); //erase first element {2,3,4,7,10}
    
    auto it2 = s.find(3); 
    auto it3 = s.find(7);

    s.erase(it2, it3); //{2,7,10}  erase elements from 3 to 7 (exclusive)

    // Count (0 or 1, because set stores unique elements)
    cout << "Count of 7: " << s.count(7) << endl; // 1   check if 7 is present
    cout << "Count of 5: " << s.count(5) << endl; // 0

    // Lower Bound and Upper Bound
    s.insert(15); // {7,10,15}
    cout << "Lower bound of 10: " << *s.lower_bound(10) << endl; // 10
    cout << "Upper bound of 10: " << *s.upper_bound(10) << endl; // 15

    // Clear set
    s.clear();
    cout << "Size after clear: " << s.size() << endl;

    return 0;
}
