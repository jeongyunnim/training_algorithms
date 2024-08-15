#include <iostream>
using namespace std;

int main() {
    int count;

    cin >> count;
    int line_len = 2 * count;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < line_len; ++j) {
            if (j < i + 1 || j > (line_len) - i - 2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < line_len; ++j) {
            if (j < line_len / 2 - i - 1 || line_len / 2 + i < j)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return (0);
}