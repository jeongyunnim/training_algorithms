//
// Created by 서정윤 on 2025. 3. 1. 오후 11:08
//
#include <bits/stdc++.h>

using namespace std;
int board[1001][1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j) {
            if (dp[i - 1][j] < dp[i][j - 1])
                dp[i][j] = board[i][j] + dp[i][j - 1];
            else
                dp[i][j] = board[i][j] + dp[i - 1][j];
        }
    }
    cout << dp[N][M];
}