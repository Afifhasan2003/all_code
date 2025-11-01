#include<iostream>
#include<algorithm>
#include <map>
using namespace std;

void properties(){
    //1. stored in sorted order based on key
    //2. key must be unique
    //3. implemented as self balancing BST (Red Black Tree)
    //4. slower than unordered_map (implemented as hash table)
    //5. time complexity: O(log n) for insert, delete, find
}

void insert(map<int, string>& m){
    // Insert elements
    m[1] = "Apple";    
    m[5] = "Banana";   
    m[3] = "Cherry";   // {1: "Apple", 3: "Cherry", 5: "Banana"} (sorted by key)

    // Alternative insert method
    m.insert({2, "Date"});   // {1,2,3,5}

    // Emplace (more efficient insert)
    m.emplace(4, "Elderberry"); // {1:"Apple", 2: "Date", 3: "Cherry", 4: "Elderberry", 5: "Banana"}
    m.emplace(3, "Fig"); // Ignored, key 3 already exists
    m.insert({3, "Fig"}); // Ignored, key 3 already exists
    m[3] = "Fig"; // overrid previous value 
}

void displayMap(const map<int, string>& m) {
    cout << "Map elements:\n";

    // for (const auto& it : m) {  // it is the actual element of the map, if edited, the map will be edited
        for (auto it : m) {         // it is a copy of the actual element of the map, if edited, the map will not be edited

            cout << it.first << " => " << it.second << endl;  //here "it" is a pair 
        }

    cout << "Using iterator:\n";
    for (auto it = m.begin(); it != m.end(); ++it) 
        cout << it->first << " => " << it->second << endl; // here it is not a pair
}

void findAnElementWithKey(const map<int, string>& m, int key) {
    auto it = m.find(key); // Find element by key
    if (it != m.end())
        cout << "Found key " << key << " with value: " << it->second << endl; // -> is used to access value when using iterator
    else
        cout << "Key " << key << " not found.\n";
}
void eraseAnElementWithKey(map<int, string>& m, int key) {
    size_t erased = m.erase(key); //  size_t is an unsigned integral type, returns number of elements erased (0 or 1 for map)
    if (erased)
        cout << "Erased key " << key << ".\n";
    else
        cout << "Key " << key << " not found to erase.\n";
}

void eraseFirst_n_elements(map<int, string>& m, int n) {
    auto it = m.begin();
     
    m.erase(it, next(it, n)); // Erase first n elements
}

void UnderstandTheBasics(){


    map<int, string> m; 
    insert(m);

    displayMap(m);


    // Size of map
    cout << "Size of map: " << m.size() << endl;
    cout<< "the map is empty or not: "<< (m.empty() ? "Empty" : "Not Empty") << endl;

    findAnElementWithKey(m, 3);

    // Erase an element by key
    m.erase(5); // {5: "Banana"} is erased

    eraseAnElementWithKey(m, 2); // {2: "Date"} is erased

    cout << "After erasing keys 5 and 2:\n";
    displayMap(m);

    // Count how many times a key exists
    cout << "Count of key 1: " << m.count(1) << endl; // Either 0 or 1

    // Lower Bound and Upper Bound
    auto lb = m.lower_bound(2); // First element >= 2
    if (lb != m.end())
        cout << "Lower bound of 2: " << lb->first << " => " << lb->second << endl;

    auto ub = m.upper_bound(3); // First element > 3
    if (ub != m.end())
        cout << "Upper bound of 3: " << ub->first << " => " << ub->second << endl;

    // Clear map
    m.clear();
    cout << "Size after clear: " << m.size() << endl;
}

void howManyTimeEachNumbersApear(){
    int arr[]={2,24,2,5,7,9,2,3,45,7,4,2,4,6,8,3,1,6,9,1,4,3,4,6,8,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxNum = *max_element(arr,arr+n);
    map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // for (int i = 0; i <= maxNum; i++)   if (mp[i] != 0)     cout<<i<<" apeared "<<mp[i]<<"times"<<endl;
       
    //or

    for(auto p: mp)     cout<<p.first <<" appeared "<<p.second<<" times"<<endl;
         
}

void frequencyOfGivenCharactersInAString(const string& str, char ch) {
    map<char, int> freqMap;
    for (char c : str) {
        freqMap[c]++;
    }

    if (freqMap.find(ch) != freqMap.end()) {
        cout << "Frequency of "<< ch << ": " << freqMap[ch] << endl;
    } else {
        cout << ch << " not found in the string.\n";
    }
    
}

int main() {
   UnderstandTheBasics();
}


