#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int> vec;
    int input;

    for (int i = 0; i < 3; i++) {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    if (vec[0] == vec[1] && vec[1] == vec[2])
        cout << 10000 + vec[0] * 1000;
    else if (vec[0] == vec[1])
        cout << 1000 + vec[0] * 100;
    else if (vec[1] == vec[2])
        cout << 1000 + vec[1] * 100;
    else
        cout << vec[2] * 100;
    return (0);
}