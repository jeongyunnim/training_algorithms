//
// Created by 서정윤 on 2024. 9. 30. 오후 2:52
//
#include <bits/stdc++.h>
#define WEI first
#define VAL second

using namespace std;

int N, K;
pair<int, int> s[101];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> s[i].WEI >> s[i].VAL;
    }

    int mx = 0;
//    int offset;
    for (int i = 1; i <= N; ++i) {
        if (s[i].WEI > K) continue ;
//        mn = min(mn, s[i].WEI);
        for (int j = 1; j <= K; ++j) {
            if (j >= s[i].WEI)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i].WEI] + s[i].VAL);
            else
                dp[i][j] = dp[i - 1][j];
            mx = max(mx, dp[i][j]);
        }
    }
//    for (int i = 1; i <= N; ++i) {
//        cout << i << ": ";
//        for (int j = 1; j <= K; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << '\n';
//    }
    cout << mx;
}