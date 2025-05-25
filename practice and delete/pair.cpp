#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;

int main() {
    // 1. Basic pair
    pair<int, string> p1 = {1, "Ironman"};
    cout << "Basic Pair: " << p1.first << ", " << p1.second << endl;

    // 2. Nested pair
    pair<int, pair<string, double>> p2 = {2, {"Jarvis", 99.9}};
    cout << "Nested Pair: " << p2.first << ", " << p2.second.first << ", " << p2.second.second << endl;

    // 3. make_pair()
    pair<char, float> p3 = make_pair('A', 3.14f);
    cout << "Make Pair: " << p3.first << ", " << p3.second << endl;

    // 4. Swapping pairs
    pair<int, int> a = {1, 2}, b = {3, 4};
    swap(a, b);
    cout << "After Swap: a = " << a.first << ", " << a.second << endl;

    // 5. Comparing pairs
    pair<int, int> x = {1, 2}, y = {1, 3};
    if (x < y) cout << "Comparison: x is smaller\n";

    // 6. Array of pairs
    pair<int, int> arr[3] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "Array of Pairs:\n";
    for (int i = 0; i < 3; i++)
        cout << arr[i].first << " " << arr[i].second << endl;

    // 7. Vector of pairs
    vector<pair<string, int>> v;
    v.push_back({"Tony", 1});
    v.emplace_back("Steve", 2);
    cout << "Vector of Pairs:\n";
    for (auto p : v)
        cout << p.first << " " << p.second << endl;

    // 8. Map with pair as value
    map<int, pair<int, int>> m1;
    m1[1] = {10, 20};
    m1[2] = make_pair(30, 40);
    cout << "Map with Pair as Value:\n";
    for (auto x : m1)
        cout << x.first << " -> " << x.second.first << ", " << x.second.second << endl;

    // 9. Map with pair as key
    map<pair<int, int>, string> m2;
    m2[{1, 2}] = "Position A";
    m2[{3, 4}] = "Position B";
    cout << "Map with Pair as Key:\n";
    for (auto x : m2)
        cout << "(" << x.first.first << ", " << x.first.second << ") -> " << x.second << endl;

    return 0;
}
