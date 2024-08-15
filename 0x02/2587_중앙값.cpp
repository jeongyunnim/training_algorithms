#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {

    vector<int> res;
    int input;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> input;
        res.push_back(input);
        sum += input;
    }
    sort(res.begin(), res.end());

    cout << sum / 5 << "\n" << res[2];
    return (0);
}