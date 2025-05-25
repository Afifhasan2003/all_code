#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements
    s.push(10);   // {10}
    s.push(20);   // {10,20}
    s.emplace(30); // {10,20,30}

    // Top element
    cout << "Top element: " << s.top() << endl; // 30

    // Pop element
    s.pop(); // removes 30, now top is 20

    cout << "After pop, top element: " << s.top() << endl; // 20

    // Size
    cout << "Stack size: " << s.size() << endl; // 2

    // Empty check
    if (s.empty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    // Clearing the stack fully
    while (!s.empty()) {
        s.pop();
    }

    cout << "After clearing, stack size: " << s.size() << endl; // 0

    return 0;
}
