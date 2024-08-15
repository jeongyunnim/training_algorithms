#include <iostream>

using namespace std;

int main(void) {
    int input;
    int count = 0;
    for (int i = 1; i <= 12; i++) {
        cin >> input;
        if (input == 0)
            ++count;
        if (i % 4 == 0) {
            if (count == 4)
                count = 4;
            else if (count == 0)
                count = 5;
            cout << static_cast<char>('A' + count - 1) << "\n";
            count = 0;
        }
    }
    return (0);
}