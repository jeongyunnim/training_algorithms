//
// Created by 서정윤 on 2024. 11. 1. 오후 5:35
//
#include <bits/stdc++.h>

using namespace std;
char board[21][21];
bool alpha[26];
int N, M;
int cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve_recur(int x, int y, int n) {
    cnt = max(cnt, n);
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || alpha[board[nx][ny] - 'A']) continue ;
        alpha[board[nx][ny] - 'A'] = true;
        solve_recur(nx, ny, n + 1);
        alpha[board[nx][ny] - 'A'] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;
    for (int i = 0; i < N * M; ++i) {
        cin >> board[i / M][i % M];
    }
    alpha[board[0][0] - 'A'] = true;
    solve_recur(0, 0, 1);
    cout << cnt;
}
