//similar to map but not sorted
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um; // Create an unordered_map

    // Insert elements
    um[1] = "Apple";
    um[5] = "Banana";
    um[3] = "Cherry";

    // Alternative insert
    um.insert({2, "Date"});

    // Emplace
    um.emplace(4, "Elderberry");

    // Display unordered_map
    cout << "Unordered Map elements:\n";
    for (auto it : um)
        cout << it.first << " => " << it.second << endl;

    // Size
    cout << "Size of unordered_map: " << um.size() << endl;

    // Find a key
    auto it = um.find(5);
    if (it != um.end())
        cout << "Found key 5 with value: " << it->second << endl;
    else
        cout << "Key 5 not found\n";

    // Erase by key
    um.erase(3);

    cout << "After erasing key 3:\n";
    for (auto it : um)
        cout << it.first << " => " << it.second << endl;

    // Count
    cout << "Count of key 1: " << um.count(1) << endl; // Either 0 or 1

    // Clear unordered_map
    um.clear();
    cout << "Size after clear: " << um.size() << endl;

    return 0;
}
