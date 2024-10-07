//
// Created by 서정윤 on 2024. 10. 7. 오후 3:36
//
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {
    int N, M;

    cin >> N >> M;
    for (int i = 1; i < 1001; ++i) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[N][M];
}