#include <bits/stdc++.h>
using namespace std;

/*
    Compute-Transition-Function(P, Σ)
*/
vector<vector<int>> computeTransitionFunction(string P, vector<char> sigma) {
    int m = P.length();
    
    // delta table (states 0,1,2,..m)
    int alphabetSize = sigma.size();    // possible ways to travel from one state to another

    vector<vector<int>> delta(m + 1, vector<int>(alphabetSize, 0));

    for (int q = 0; q <= m; q++) {      //for each state
        for (char a : sigma) {          //all possible input characters
            
            int k = min(m, q + 1);

            while (k > 0) {
                string prefix = P.substr(0, k);
                string temp = P.substr(0, q) + a;

                // check if prefix is suffix of temp
                if (temp.size() >= prefix.size() &&
                    temp.substr(temp.size() - prefix.size()) == prefix) {       //first comparing bigger prefixes
                    break;
                }
                k--;
            }

            delta[q][a] = k;
        }
    }

    return delta;
}


/*
    Finite-Automaton-Matcher(T, δ, P)
*/
void finiteAutomatonMatcher(string T, string P, vector<vector<int>> &delta) {
    int n = T.length();
    int m = P.length();
    
    int q = 0;  // start state

    for (int i = 0; i < n; i++) {
        q = delta[q][T[i]];

        if (q == m) {
            cout << "Pattern occurs at index "
                 << i - m + 1 << endl;
        }
    }
}


/*
    Main Function
*/
int main() {
    string text, pattern;

    // cout << "Enter text: ";
    // cin >> text;
    // cout << "Enter pattern: ";
    // cin >> pattern;

    text = "ababcababcabc";
    pattern = "abc";

    // Define alphabet (simple: characters in pattern)
    set<char> s(pattern.begin(), pattern.end());

    vector<char> sigma(s.begin(), s.end()); // convert set to vector

    vector<vector<int>> delta =
        computeTransitionFunction(pattern, sigma);  //transition function

    finiteAutomatonMatcher(text, pattern, delta);

    

    return 0;
}