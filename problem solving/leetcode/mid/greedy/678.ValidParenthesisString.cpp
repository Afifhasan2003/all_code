#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{

    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if ((s[i] == '(' && s[j] == '(') || (s[i] == ')' && s[j] == ')'))
        {
            cout << "first here" << endl;
            return false;
        }
        cout<<"i="<<i<<" j="<<j<<endl;
        i++;
        j--;
    }

    if (
        (s[i] == '(' && s[j] == ')') || (s[i] == ')' && s[j] == '(') || s[i] == '*' || s[j] == '*')

    {
        cout << "did it enter" << endl;
        return true;
    }

    cout << "here last";
    return false;
}

int main()
{

    string s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()";

    cout << checkValidString(s);
    return 0;
}