//
// Created by 서정윤 on 2024. 11. 12. 오후 3:15
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
char board[101][101];
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    queue<pair<int, int> > Q;

    cin >> N >> M;
    for (int i = 0; i < N * M; ++i) {
        cin >> board[i / M][i % M];
    }
    int cnt = 0;
    for (int i = 0; i < N * M; ++i) {
        int x = i / M, y = i % M;
        if (board[x][y] == '.' || visited[x][y]) continue ;
        Q.push({x, y});
        visited[x][y] = true;
        cnt += 1;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
                if (board[nx][ny] == '.' || visited[nx][ny]) continue ;
                visited[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
    cout << cnt;
}