//
// Created by 서정윤 on 2024. 12. 4. 오후 4:36
//
#include <bits/stdc++.h>

using namespace std;
int L[21];
int J[21];
int dp[21][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> L[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> J[i];
    }
    int mx = 0;
    for (int i = 1; i <= N; ++i) {
        int weight = L[i];
        int joy = J[i];
        for (int j = 0; j < 100; ++j) {
            if (j >= weight) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + joy);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            mx = max(mx, dp[i][j]);
        }

    }
    cout << mx;
}