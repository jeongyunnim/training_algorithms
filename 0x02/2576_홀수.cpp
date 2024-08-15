#include <iostream>

using namespace std;

int main(void) {

    int min = -1;
    int sum = 0;
    int temp = -1;

    for (int i = 0; i < 7; i++) {
        cin >> temp;
        if (temp % 2 == 1) {
            sum += temp;
            if (min == -1 || temp < min) {
                min = temp;
            }
        }
    }
    if (min == -1)
        cout << min;
    else
        cout << sum << "\n" << min;
    return (0);
}