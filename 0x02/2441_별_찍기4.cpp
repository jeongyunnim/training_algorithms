#include <iostream>
using namespace std;

int main() {
    int count;

    cin >> count;
    for (int i = count; i > 0; --i) {
        for (int j = count; j > 0; --j) {
            if (j > i)
                cout << " ";
            else
                cout << "*";
        }
        cout << "\n";
    }
}