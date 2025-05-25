//map is 

#include<iostream>
#include<algorithm>
#include <map>
using namespace std;

void UnderstandTheBasics(){


    map<int, string> m; // Create a map (Key: int, Value: string)

    // Insert elements
    m[1] = "Apple";    // {1: "Apple"}
    m[5] = "Banana";   // {1: "Apple", 5: "Banana"}
    m[3] = "Cherry";   // {1: "Apple", 3: "Cherry", 5: "Banana"} (sorted by key)

    // Alternative insert metho/* code */d
    m.insert({2, "Date"});   // {1,2,3,5}

    // Emplace (more efficient insert)
    m.emplace(4, "Elderberry"); // {1:"Apple", 2: "Date", 3: "Cherry", 4: "Elderberry", 5: "Banana"}

    // Display map
    cout << "Map elements:\n";
    for (auto it : m)
        cout << it.first << " => " << it.second << endl;

    // Size of map
    cout << "Size of map: " << m.size() << endl;

    // Find an element by key
    auto it = m.find(3); // Finds key 3
    if (it != m.end())
        cout << "Found key 3 with value: " << it->second << endl;       // -> is used to access value when using iterator
    else
        cout << "Key 3 not found.\n";

    // Erase an element by key
    m.erase(5); // {5: "Banana"} is erased

    // Erase using iterator
    it = m.find(2);
    if (it != m.end())
        m.erase(it); // {2: "Date"} is erased

    cout << "After erasing keys 5 and 2:\n";
    for (auto it : m)
        cout << it.first << " => " << it.second << endl;

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

void howManyTimeANumberApear(){
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


int main() {
 
    howManyTimeANumberApear();

    return 0;
}
