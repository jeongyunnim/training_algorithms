#include <iostream>
using namespace std;

int main() {
    int count;

    cin >> count;
    int line_len = 2 * count - 1;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < line_len; ++j) {
            if (j < i)
                cout << " ";
            else if (j > (line_len) - i - 1)
                break ;
            else
                cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i < count ; ++i) {
        for (int j = 0; j < line_len; ++j) {
            if (j < line_len / 2 - i)
                cout << " ";
            else if (line_len / 2 + i < j)
                break ;
            else
                cout << "*";
        }
        cout << "\n";
    }
    return (0);
}