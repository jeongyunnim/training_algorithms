//
// Created by 서정윤 on 2024. 11. 15. 오후 5:53
//
#include <bits/stdc++.h>

using namespace std;
int coins[21];
int dp[10001];

void print(int target) {
    cout << "[dp]" << '\n';
    for (int j = 0; j <= target; ++j) {
        cout << j << " ";
    }
    cout << '\n';
    for (int j = 0; j <= target; ++j) {
        cout << dp[j] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, target;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> coins[i];
        }
        cin >> target;
        bzero(dp, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < N; ++i) {
            int coin = coins[i];
            for (int j = coin; j <= target; ++j) {
                dp[j] += dp[j - coin];
            }
        }
//        print(target);
        cout << dp[target] << '\n';
    }
}