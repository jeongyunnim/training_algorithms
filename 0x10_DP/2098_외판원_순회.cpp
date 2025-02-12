//
// Created by 서정윤 on 2025. 2. 10. 오후 9:48
//
#include <bits/stdc++.h>

using namespace std;
int N;
int board[16][16];
int dp[16][1 << 16];

int find_least(int cur, int visited) {
    if (visited == (1 << N) - 1) {
        if (!board[cur][0])
            return 0x7fffffff / 2; // 돌아오는 길이 없을 수도 있다.
        return (board[cur][0]);
    }
    if (dp[cur][visited])
        return dp[cur][visited];
    dp[cur][visited] = 0x7fffffff / 2;
    for (int i = 1; i < N; ++i) {
        if (visited & (1 << i) || !board[cur][i]) continue ;
        dp[cur][visited] = min(dp[cur][visited], find_least(i, visited | (1 << i)) + board[cur][i]);
    }
    return dp[cur][visited];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    cout << find_least(0, 1);
}