// gpt

#include <bits/stdc++.h>
using namespace std;


vector<int> rabinKarpSimple(string text, string pattern) {

    int n = text.length();
    int m = pattern.length();
    
    vector<int> result;
    if (m > n) return result;

    // Count unique characters in text + pattern
    unordered_set<char> uniqueChars;
    for(char c : text) uniqueChars.insert(c);
    for(char c : pattern) uniqueChars.insert(c);

    int base = uniqueChars.size();   // dynamic base

    unsigned long long patternHash = 0;
    unsigned long long windowHash  = 0;
    unsigned long long offset = 1;   // base^(m-1)

    // Compute base^(m-1)
    for(int i = 0; i < m - 1; i++)
        offset *= base;

    // Initial hashes
    for(int i = 0; i < m; i++) {
        patternHash = patternHash * base + pattern[i];  //pattern[i] is the ascii value of the character
        windowHash  = windowHash  * base + text[i];
    }

    // Sliding window
    for(int i = 0; i <= n - m; i++) {

        if(patternHash == windowHash) {
            bool match = true;
            for(int j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if(match)
                result.push_back(i);
        }

        if(i < n - m) {
            // Remove left character
            windowHash -= text[i] * offset;

            // Add new character
            windowHash = windowHash * base + text[i + m];
        }
    }

    return result;
}


vector<int> rabinKarp_withMOD(string text, string pattern)
{
    // const int base = 256;       // number of possible characters
    unordered_set<char> uniqueChars;
    for (char c : text)
        uniqueChars.insert(c);
    for (char c : pattern)
        uniqueChars.insert(c);

    int base = uniqueChars.size(); // dynamic base





    const int mod = 1e9 + 7; // large prime to avoid overflow: overflow happens typically after 10^18 for unsigned long long

    int n = text.length();
    int m = pattern.length();

    vector<int> result;
    if (m > n)
        return result;

    long long patternHash = 0;
    long long windowHash = 0; // hash of current substring in text
    long long offset = 1;     // base^(m-1)

    // Compute base^(m-1) % mod
    for (int i = 0; i < m - 1; i++) // offset for the first character in the window
        offset = (offset * base) % mod;

    // Compute initial hashes
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
    }

    // Sliding window
    for (int i = 0; i <= n - m; i++)
    {

        // If hash matches, verify manually
        if (patternHash == windowHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                result.push_back(i);
        }

        // Compute next window hash
        if (i < n - m)
        {
            windowHash = ((windowHash - text[i] * offset % mod) + mod) % mod; // last to two mod are here to avoid negative value, coz neg values are not allowd
            windowHash = (windowHash * base + text[i + m]) % mod;
        }
    }

    return result; // returns starting indices of matches
}

int main()
{
    string text = "ababcababcabc";
    string pattern = "abc";

    cout << "Using Rabin-Karp without modulus:" << endl;
    vector<int> matches1 = rabinKarpSimple(text, pattern);  
    for (int index : matches1)
        cout << "Pattern found at index: " << index << endl;    



    cout << "\nUsing Rabin-Karp with modulus:" << endl;
    vector<int> matches2 = rabinKarp_withMOD(text, pattern);

    for (int index : matches2)
        cout << "Pattern found at index: " << index << endl;
}