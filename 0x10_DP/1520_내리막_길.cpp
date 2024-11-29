//
// Created by 서정윤 on 2024. 11. 29. 오후 3:19
//
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N, M;
int board[501][501];
int visited[501][501];

void print_visited() {
    cout << "[visited]\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int DFS(int x, int y) {
    if (x == N - 1 && y == M - 1)
        return 1;
    if (visited[x][y] != -1)
        return visited[x][y];
    visited[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
        if (board[nx][ny] >= board[x][y]) continue ;
        visited[x][y] += DFS(nx, ny);
    }
    return visited[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            visited[i][j] = -1;
        }
    }
    cout << DFS(0, 0);
}