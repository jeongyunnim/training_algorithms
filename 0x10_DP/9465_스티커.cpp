//
// Created by 서정윤 on 2024. 10. 24. 오후 4:55
//
#include <bits/stdc++.h>

using namespace std;
int T, N;
int stickers[100001][2];
int dp[100001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> stickers[i][0];
        }
        for (int i = 1; i <= N; ++i) {
            cin >> stickers[i][1];
        }
        dp[1][0] = stickers[1][0];
        dp[1][1] = stickers[1][1];
        dp[2][0] = stickers[1][1] + stickers[2][0];
        dp[2][1] = stickers[1][0] + stickers[2][1];
        for (int i = 3; i <= N; ++i) {
            dp[i][0] = max({dp[i - 1][1], dp[i - 2][0], dp[i - 2][1]}) + stickers[i][0];
            dp[i][1] = max({dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]}) + stickers[i][1];
        }
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }
}