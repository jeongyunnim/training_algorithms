//
// Created by 서정윤 on 2024. 9. 26. 오후 10:17
//
#include <iostream>
#include <algorithm>

using namespace std;
/*
 * dp[Tree][Time][Move]
 */
int dp[3][1001][32];
int tree[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, W;

    cin >> T >> W;
    for (int i = 1; i <= T; ++i) {
        cin >> tree[i];
    }

    if (tree[1] == 1) {
        dp[1][1][1] = 1;
    } else {
        dp[2][1][2] = 1;
    }
    for (int i = 2; i <= T; ++i) {
        // W + 1까지 도는 이유?
        for (int mv = 1;  mv <= W + 1; ++mv) {
            if (tree[i] == 1) {
                dp[1][i][mv] = max(dp[1][i - 1][mv], dp[2][i - 1][mv - 1]) + 1;
                dp[2][i][mv] = max(dp[1][i - 1][mv - 1], dp[2][i - 1][mv]);
            } else {
                dp[1][i][mv] = max(dp[1][i - 1][mv], dp[2][i - 1][mv - 1]);
                dp[2][i][mv] = max(dp[1][i - 1][mv - 1], dp[2][i - 1][mv]) + 1;
            }
        }
    }

//    cout << "나무 1" << '\n';
//    for (int mv = 1;  mv <= W + 1; ++mv) {
//        for (int i = 1; i <= T; ++i) {
//            cout << i << ", " << mv << '\n';
//            cout << dp[1][i][mv] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << "나무 2" << '\n';
//    for (int mv = 1;  mv <= W + 1; ++mv) {
//        for (int i = 1; i <= T; ++i) {
//            cout << dp[2][i][mv] << ' ';
//        }
//        cout << '\n';
//    }
    int res = -1;
    for (int i = 1; i <= W + 1; ++i) {
        res = max({res, dp[1][T][i], dp[2][T][i]});
    }
    cout << res;
}