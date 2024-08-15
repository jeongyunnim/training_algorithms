#include <iostream>
using namespace std;

int main() {
    int count;

    cin >> count;
    for (int i = 0; i < 2 * count - 1; ++i) {
        if (i < count) {
            for (int j = 0; j < count - i - 1; ++j)
                cout << " ";
            for (int j = 0; j < 2 * i + 1; ++j)
                cout << "*";
        }
        else {
            for (int j = 0; j < (i - count) + 1; ++j)
                cout << " ";
            for (int j = 0; j < (2 * count - 1) - 2 * (i - count + 1); ++j)
                cout << "*";
        }
        cout << "\n";
    }
}