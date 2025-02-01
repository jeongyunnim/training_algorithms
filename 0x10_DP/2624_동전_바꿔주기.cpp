//
// Created by 서정윤 on 2025. 2. 1. 오전 10:37
//
#include <bits/stdc++.h>

using namespace std;
int DP[10001];
pair<int, int> coins[100];
int T, K;

void print() {
    for (int i = 0; i <= T; ++i)
        cout << setw(4) << i;
    cout << '\n';
    for (int i = 0; i <= T; ++i)
        cout << setw(4) << DP[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> K;
    for (int i = 0; i < K; ++i) {
        cin >> coins[i].first >> coins[i].second;
    }
    sort(coins, coins + K, greater<pair<int, int> >() );
    DP[0] = 1;
    for (int i = 0; i < K; ++i) {
        int coin, cnt;
        tie(coin, cnt) = coins[i];
        for (int j = T; j >= 0; --j) {
            if (!DP[j]) continue ;
            for (int k = 1; k <= cnt; ++k) {
                if (k * coin + j > T) break ;
                DP[k * coin + j] += DP[j];
            }
        }
    }
    cout << DP[T];
}