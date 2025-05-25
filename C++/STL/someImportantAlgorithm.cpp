#include <bits/stdc++.h>
using namespace std;

// Sort with custom comparator
bool comp(int a, int b) {
    return a > b; // Descending order
    //we would customize this to sort by any logic we want
}

void example_sort_with_comp() {
    vector<int> v = {5, 2, 9, 1, 5, 6};
    sort(v.begin(), v.end(), comp);
    for (int x : v) cout << x << " ";
    cout << endl;
}

// 
void example_builtin_popcount() {
    int x = 29; // binary: 11101
    // int bit = __builtin_popcount(x);  //we can do this 
    cout << __builtin_popcount(x) << endl;

    long long y = 123456789123;
    cout << __builtin_popcountll(y) << endl;
}

// Next permutation
void example_next_permutation() {

    string s = "bac";
    sort(s.begin(), s.end());     // "abc" to get all permutations
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));




    vector<int> v = {1, 2, 3};
    do {
        for (int x : v) cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
}

// Max element
void example_max_element() {
    vector<int> v = {10, 20, 5, 23, 15};
    int mx = *max_element(v.begin(), v.end());
    cout << "Maximum element: " << mx << endl;
}

int main() {
    // Functions are written for note keeping.
    // No calls made here.
    return 0;
}
