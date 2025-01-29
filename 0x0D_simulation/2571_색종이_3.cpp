//
// Created by 서정윤 on 2025. 1. 29. 오후 2:11
//
#include <bits/stdc++.h>

using namespace std;
int board[101][101];
int dp[101][101]; // 최장 가로를 저장할 dp 배열

void fill_square(int x, int y) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            board[x - i][y + j] = 1;
        }
    }
}

int find_biggest() {
    int biggest = 0;
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (board[i][j] == 0) continue ;
            dp[i][j] = dp[i - 1][j] + 1;
        }
    }
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (board[i][j] == 0) continue ;
            int cnt = 0;
            int height = dp[i][j];
            for (int k = j; k <= 100; ++k) {
                if (!dp[i][k]) break ;
                if (dp[i][k] != height) {
                    biggest = max(biggest, height * cnt);
                    height = min(height, dp[i][k]);
                }
                cnt += 1;
            }
            biggest = max(biggest, height * cnt);
        }
    }
    return biggest;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        fill_square(100 - y, x);
    }
    cout << find_biggest();
}