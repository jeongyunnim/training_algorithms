//
// Created by 서정윤 on 2024. 10. 9. 오후 4:50
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    bool room[101];
    cin >> T;
    while (T--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n / i; ++i) {
            sum += 1;
        }
        cout << sum << '\n';
    }
}