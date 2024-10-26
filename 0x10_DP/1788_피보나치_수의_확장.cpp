//
// Created by 서정윤 on 2024. 10. 26. 오후 4:35
//
#include <bits/stdc++.h>

using namespace std;
long long dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    if (N < 0) {
        N *= -1;
        if (N % 2 == 1) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    } else if (N == 0) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    }
    cout << dp[N];
}