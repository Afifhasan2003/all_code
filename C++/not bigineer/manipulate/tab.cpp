#include <iostream>
using namespace std;

// Custom manipulator for tab
ostream& tab(ostream &os) {
    return os.put('\t');
}

int main() {
    cout << "Name" << tab << "Age" << tab << "City" << endl;
    cout << "John" << tab << 25 << tab << "New York" << endl;
    cout << "Jane" << tab << 30 << tab << "Los Angeles" << endl;
    cout << "Doe" << tab << 22 << tab << "Chicago" << endl;
    return 0;
}
