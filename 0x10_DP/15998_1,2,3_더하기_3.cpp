//
// Created by 서정윤 on 2024. 10. 21. 오후 4:56
//
#include <bits/stdc++.h>

using namespace std;

long long dp[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 1000001; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
    }
    int x;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        cout << dp[x] << '\n';
    }

}