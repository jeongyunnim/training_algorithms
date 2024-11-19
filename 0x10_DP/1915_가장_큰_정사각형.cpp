//
// Created by 서정윤 on 2024. 11. 19. 오후 1:47
//
#include <bits/stdc++.h>

using namespace std;
char board[1001][1001];
int visited[1001][1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == '0') continue ;
            visited[i][j] = 1;
            if (i > 0 && j > 0)
                visited[i][j] = min({visited[i - 1][j], visited[i][j - 1], visited[i - 1][j - 1]}) + 1;
            mx = max(mx, visited[i][j]);
        }
    }
    cout << mx * mx;
}