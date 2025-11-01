#include <iostream>
#include <set>
using namespace std;

void properties(){
    // Properties of set:
    // 1. Stores unique elements only (no duplicates).
    // 2. Elements are sorted in ascending order by default.
    // 3. Implemented as a balanced binary search tree (usually a Red-Black Tree).
    // 4. Provides logarithmic time complexity for insert, delete, and find operations.
    // 5. Does not allow direct access to elements via indexing (like arrays or vectors).
    // 6. Supports iterators for traversal.
    // 7. Can be customized with a comparator for different sorting orders.

 //in CP first we try to use unorder_set, if TLE then we use set
//in set we can do lower_bound and upper_bound
//we can also delete a range of elements in set
//we can copy one set to another set easily


}




void display(const set<int>& s) {
     // Display set
    cout << "Set elements:\n";
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}

void iterateSet(const set<int>& s){
    // Iterate through set
    cout << "Iterating through set:\n";
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void deleteFromTheStart(set<int>& s, int n){

    auto it = s.begin();
    advance(it, n); // Move iterator to the nth position
    s.erase(s.begin(), it); // [first, last) 

    //OR we can just 
    // s.erase(s.begin(), next(s.begin(), n)); 

    //if set = {1,2,3,4,5,6} and n=3
    //after this operation set = {4,5,6} 
}                                      

void deleteFrom_atob(set<int>& s, int a, int b){
    auto it1 = s.lower_bound(a); // Points to the first element not less than or equal to a
    auto it2 = s.lower_bound(b); // Points to the first element greater than or equal to b
    s.erase(it1, it2); // [it1, it2) 

    //if set = {1,2,3,4,5,6} and a=2,b=4
    //after this operation set = {1,4,5,6} 
}

void copySet(const set<int>& source, set<int>& destination){
    destination.insert(source.begin(), source.end());
    //OR we can just
    // destination = source;  if we want to copy all elements
}



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

    display(s);

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
    display(s);

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
