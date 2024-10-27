//
// Created by 서정윤 on 2024. 10. 27. 오후 7:09
//
#include <bits/stdc++.h>

using namespace std;
long long input[100001][3];
long long dp[100001][3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k = 1, N;
    while (1) {
        cin >> N;
        if (N == 0) {
            return 0;
        }
        for (int i = 0; i < N; ++i) {
            cin >> input[i][0] >> input[i][1] >> input[i][2];
        }
        dp[0][0] = 0x7fffffff;
        dp[0][1] = input[0][1];
        dp[0][2] = input[0][1] + input[0][2];
        for (int i = 1; i < N; ++i) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + input[i][0];
            dp[i][1] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + input[i][1];
            dp[i][2] = min({dp[i][1], dp[i - 1][2], dp[i - 1][1]}) + input[i][2];
//            cout << "\t" << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
        }
        cout << k << ". " << dp[N - 1][1] << '\n';
        k++;
    }
}