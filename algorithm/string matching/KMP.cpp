#include <iostream>
#include <vector>
using namespace std;


// Compute Prefix Function (Π)
vector<int> computePrefixFunction(string p) {       // p= pattern
    int m = p.length();
    vector<int> pi(m);

    pi[0] = 0;     // Π[1] = 0 (slide uses 1-based index)
    int k = 0;     // length of the longest prefix that is also a suffix for the substring p[0..q]

    // q is used to iterate through the pattern conveniently, starting from the second character (index 1)
    for (int q = 1; q < m; q++) {   // q = 2 to m (1-based)
        while (k > 0 && p[k] != p[q]) {
            k = pi[k - 1];
        }

        if (p[k] == p[q]) {
            k = k + 1;
        }

        pi[q] = k;      // pi[1] is always 0
    }

    return pi;
}

// KMP Matcher
void KMPMatcher(string S, string p) {
    int n = S.length();
    int m = p.length();

    vector<int> pi = computePrefixFunction(p);

    int q = 0;  // number of characters matched

    for (int i = 0; i < n; i++) {   // scan S left to right

        while (q > 0 && p[q] != S[i]) {
            q = pi[q - 1];
        }

        if (p[q] == S[i]) {
            q = q + 1;
        }

        if (q == m) {
            cout << "Pattern occurs with shift "
                 << i - m + 1 << endl;

            q = pi[q - 1];   // look for next match
        }
    }
}

// Main Function
int main() {
    string S, p;

    // cout << "Enter text: ";
    // cin >> S;

    // cout << "Enter pattern: ";
    // cin >> p;

    S = "ababcababcabc";
    p = "abc";

    KMPMatcher(S, p);

    return 0;
}