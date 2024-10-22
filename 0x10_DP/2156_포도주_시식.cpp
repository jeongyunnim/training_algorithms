//
// Created by 서정윤 on 2024. 10. 21. 오후 3:20
//
#include <bits/stdc++.h>

using namespace std;
int N;
int input[10001];
// 1: 이 잔을 선택하지 않았을 때 최댓값
// 2: 이 잔을 1로 선택했을 때 최댓값.
// 2: 이 잔을 2로 선택했을 때 최댓값.
//int dp[10001][3];

int dp[10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> input[i];
    }
    if (N == 1) {
        cout << input[1];
        return 0;
    }
//int dp[10001][3];
//    dp[1][1] = input[1];
//    dp[1][2] = 0;
//
//    int mx = 0;
//    for (int i = 2; i <= N; ++i) {
//        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
//        dp[i][1] = max({dp[i - 2][1], dp[i - 2][2], dp[i - 1][0]}) + input[i];
//        dp[i][2] = dp[i - 1][1] + input[i];
//        mx = max({mx, dp[i][1], dp[i][2]});
//    }

    dp[1] = input[1];
    int mx = 0;
    for (int i = 2; i <= N; ++i) {
        //             선택하지 않음, 1번째로 선택한 경우      , 2번째로 선택한 경우
        dp[i] = max({dp[i - 1], dp[i - 2] + input[i], dp[i - 3] + input[i - 1] + input[i]});
//        dp[i] = max({dp[i - 1], dp[i - 2] + input[i]});
        mx = max(mx, dp[i]);
    }
    cout << mx;
}