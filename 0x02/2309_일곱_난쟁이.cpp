//
// Created by 서정윤 on 8/17/24.
//
#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int dwafs[9];
    int out[2];
    int two = -100;

    for (int i = 0; i < 9; i++) {
        cin >> dwafs[i];
        two += dwafs[i];
    }
    sort(dwafs, dwafs + 9);
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (two == dwafs[i] + dwafs[j]) {
                out[0] = i; out[1] = j;
                break ;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (i != out[0] && i != out[1])
            cout << dwafs[i] << '\n';
    }
    return 0;
}