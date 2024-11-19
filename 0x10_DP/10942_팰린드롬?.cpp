//
// Created by 서정윤 on 2024. 11. 19. 오후 3:38
//
#include <bits/stdc++.h>

using namespace std;
int seq[2001];
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> seq[i];
    }
    dp[N][N] = true;
    dp[N - 1][N - 1] = true;
    if (seq[N] == seq[N - 1])
        dp[N - 1][N] = true;
    for (int i = N - 2; i > 0; --i) {
        for (int j = i; j <= N; ++j) {
            if (j == i)
                dp[i][j] = true;
            else if (j == i + 1) {
                if (seq[i] == seq[j])
                    dp[i][j] = true;
            } else {
                if (seq[i] == seq[j])
                    dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}