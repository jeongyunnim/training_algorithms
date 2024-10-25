//
// Created by 서정윤 on 2024. 10. 25. 오후 4:54
//
#include <bits/stdc++.h>

using namespace std;
int N, K;
int coins[101];
int dp[100001];

void print_dp() {
    cout << "[dp]" << '\n';
    for (int j = 0; j <= K; ++j) {
        cout << j << " ";
    }
    cout << '\n';
    for (int j = 0; j <= K; ++j) {
        cout << dp[j] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    sort(coins, coins + N);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        int coin = coins[i];
        for (int j = coin; j <= K; ++j) {
            dp[j] += dp[j - coin];
        }
//        print_dp();
    }
    cout << dp[K];
}