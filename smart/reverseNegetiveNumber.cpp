#include <bits/stdc++.h>
using namespace std;

// Reverses the number with sign handling (smart logic)
int reverseNumber(int x) {
    int rev = 0;
    while (x != 0) {
        int digit = x % 10;
        // Overflow check
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;
        rev = rev * 10 + digit;         
        x /= 10;                    //-4
                                    // -40 -3
                                    //-430 - 2
                                    //-4320-1 = -4321
    }
    return rev;
}

// Shows how % and / keep the negative sign
void showNegativeDivision(int x) {
    while (x != 0) {
        cout << x% 10<< endl;       //each number is negetive
        x /= 10;
    }
}

int main() {
    int num = -1234;
    
    cout << "Reversed: " << reverseNumber(num) << endl;
    cout << "\nNegative Division & Mod Demo:\n";
    showNegativeDivision(num);

    return 0;
}
