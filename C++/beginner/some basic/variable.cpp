#include <iostream>
using namespace std;

int main() {
    int a = 2;                // 4 bytes, range: -2,147,483,648 to 2,147,483,647
    float b = 4;              // 4 bytes, approx range: 1.2e-38 to 3.4e+38
    double bd = 4;            // 8 bytes, approx range: 2.2e-308 to 1.8e+308
    long double ld = 4;       // 16 bytes, platform-dependent
    char c = 'g';             // 1 byte, -128 to 127 (signed) or 0 to 255 (unsigned)
    bool d = 1;               // 1 byte, true/false

    // Type modifiers
    long int e;               // 8 bytes, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
    long long int ll;         // 8 bytes, same as long int
    short int f;              // 2 bytes, range: -32,768 to 32,767
    signed int g;             // 4 bytes, same as int
    unsigned int h = 5;       // 4 bytes, range: 0 to 4,294,967,295

    cout << "size of int : " << sizeof(int) << " bytes" << endl;
    cout << "size of float : " << sizeof(float) << " bytes" << endl;
    cout << "size of double : " << sizeof(double) << " bytes" << endl;
    cout << "size of long double : " << sizeof(long double) << " bytes" << endl;
    cout << "size of char : " << sizeof(char) << " bytes" << endl;
    cout << "size of bool : " << sizeof(bool) << " bytes" << endl;
    cout << "size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "size of signed int : " << sizeof(signed int) << " bytes" << endl;
    cout << "size of unsigned int : " << sizeof(unsigned int) << " bytes" << endl;

    return 0;
}
