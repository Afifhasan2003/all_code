//similar to map but allows duplicate keys
#include <iostream>
#include <map> // For multimap
using namespace std;

int main() {
    multimap<int, string> mm; // Create a multimap

    // Insert elements
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Avocado"}); // Duplicate key allowed
    mm.emplace(3, "Cherry");
    mm.emplace(2, "Blueberry");

    // Display multimap
    cout << "Multimap elements:\n";
    for (auto it : mm)
        cout << it.first << " => " << it.second << endl;

    // Size of multimap
    cout << "Size of multimap: " << mm.size() << endl;

    // Find first occurrence of key
    auto it = mm.find(2);
    if (it != mm.end())
        cout << "First key 2 found with value: " << it->second << endl;

    // Erase all entries of key 1
    mm.erase(1);

    cout << "After erasing key 1:\n";
    for (auto it : mm)
        cout << it.first << " => " << it.second << endl;

    // Lower and Upper bound
    auto lb = mm.lower_bound(2); // First key >= 2
    if (lb != mm.end())
        cout << "Lower bound of 2: " << lb->first << " => " << lb->second << endl;

    auto ub = mm.upper_bound(2); // First key > 2
    if (ub != mm.end())
        cout << "Upper bound of 2: " << ub->first << " => " << ub->second << endl;

    // Clear multimap
    mm.clear();
    cout << "Size after clear: " << mm.size() << endl;

    return 0;
}
