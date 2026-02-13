#include <bits/stdc++.h>
using namespace std;

int idx(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return 2;
}

bool dfaEndsWithAB(const string &s) {
    int TF[3][3] = {
        {1, 0, 0},   // state 0
        {1, 2, 0},   // state 1
        {1, 0, 0}    // state 2 (accept)
    };

    int state = 0;
    for (char c : s)
        state = TF[state][idx(c)];

    return state == 2;
}

bool dfaContainsC(const string &s) {
    int TF[2][3] = {
        {0, 0, 1},   // state 0
        {1, 1, 1}    // state 1 (accept)
    };

    int state = 0;
    for (char c : s)
        state = TF[state][idx(c)];

    return state == 1;

}

bool dfaEvenA(const string &s) {
    int TF[2][3] = {
        {1, 0, 0},   // state 0 (accept)
        {0, 1, 1}    // state 1
    };

    int state = 0;
    for (char c : s)
        state = TF[state][idx(c)];

    return state == 0;
}

bool dfaStartsWithA(const string &s) {
    if (s.empty()) return false;

    int TF[2][3] = {
        {1, 0, 0},   // state 0
        {1, 1, 1}    // state 1 (accept)
    };

    int state = 0;
    for (char c : s)
        state = TF[state][idx(c)];

    return state == 1;
}

bool dfaNoBC(const string &s) {
    int TF[3][3] = {
        {0, 1, 0},   // state 0
        {0, 1, 2},   // state 1
        {2, 2, 2}    // trap state
    };

    int state = 0;
    for (char c : s)
        state = TF[state][idx(c)];

    return state != 2;
}



int main() {
    string s;
    cin >> s;

    cout << "Ends with 'ab': "
         << (dfaEndsWithAB(s) ? "ACCEPTED" : "REJECTED") << endl;

    cout << "Contains at least one 'c': "
         << (dfaContainsC(s) ? "ACCEPTED" : "REJECTED") << endl;

    cout << "Even number of 'a': "
         << (dfaEvenA(s) ? "ACCEPTED" : "REJECTED") << endl;

    cout << "Starts with 'a': "
         << (dfaStartsWithA(s) ? "ACCEPTED" : "REJECTED") << endl;

    cout << "Does NOT contain 'bc': "
         << (dfaNoBC(s) ? "ACCEPTED" : "REJECTED") << endl;

    return 0;
}
