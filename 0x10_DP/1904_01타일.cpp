//
// Created by 서정윤 on 2024. 10. 26. 오후 3:45
//
#include <bits/stdc++.h>

using namespace std;
int dp[1000001];

int main() {
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout << dp[N];
}