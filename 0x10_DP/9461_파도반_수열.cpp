//
// Created by 서정윤 on 2024. 9. 25. 오전 12:00
//
#include <iostream>

using namespace std;

long long tri[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;

    tri[1] = tri[2] = tri[3] = 1;
    tri[4] = tri[5] = 2;
    tri[6] = 3;
    for (int i = 7; i < 101; ++i) {
        tri[i] = tri[i - 1] + tri[i - 5];
    }

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        cout << tri[N] << '\n';
    }
}