#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    const int n = 100000; // 1 lakh insertions

    // Vector test
    vector<int> v;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        v.insert(v.begin(), i); // inserting at front, slow for vector
    }
    auto end = high_resolution_clock::now();
    cout << "Vector insert front time: " 
         << duration_cast<milliseconds>(end - start).count() 
         << " ms" << endl;

    // Deque test
    deque<int> d;
    start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        d.push_front(i); // optimized for front
    }
    end = high_resolution_clock::now();
    cout << "Deque push_front time: " 
         << duration_cast<milliseconds>(end - start).count() 
         << " ms" << endl;

    // List test
    list<int> l;
    start = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        l.push_front(i); // super fast
    }
    end = high_resolution_clock::now();
    cout << "List push_front time: " 
         << duration_cast<milliseconds>(end - start).count() 
         << " ms" << endl;

    return 0;
}
