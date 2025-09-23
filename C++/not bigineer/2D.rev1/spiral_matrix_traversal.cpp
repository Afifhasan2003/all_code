#include<iostream>
using namespace std;

int main() {
    int n = 5, m = 6;
    int arr[5][6] = {
        {1,  2,  3,  4,  5,  6},
        {18, 19, 20, 21, 22, 7},
        {17, 28, 29, 30, 23, 8},
        {16, 27, 26, 25, 24, 9},
        {15, 14, 13, 12, 11, 10}
    };

    int rowStart = 0, rowEnd = n - 1, columnStart = 0, columnEnd = m - 1;

    while (rowStart <= rowEnd && columnStart <= columnEnd) {
        // Traverse rowStart
        for (int col = columnStart; col <= columnEnd; col++) {
            cout << arr[rowStart][col] << " ";
        }
        rowStart++;

        // Traverse columnEnd
        for (int row = rowStart; row <= rowEnd; row++) {
            cout << arr[row][columnEnd] << " ";
        }
        columnEnd--;

        // Traverse rowEnd (check needed to avoid double print in odd rows)
        if (rowStart <= rowEnd) {
            for (int col = columnEnd; col >= columnStart; col--) {
                cout << arr[rowEnd][col] << " ";
            }
            rowEnd--;
        }

        // Traverse columnStart (check needed to avoid double print in odd cols)
        if (columnStart <= columnEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                cout << arr[row][columnStart] << " ";
            }
            columnStart++;
        }
    }

    return 0;
}
