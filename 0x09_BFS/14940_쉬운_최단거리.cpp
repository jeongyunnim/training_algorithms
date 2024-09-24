//
// Created by 서정윤 on 2024. 9. 24. 오후 8:26
//
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0 , -1};
int map[1001][1001];
int visited[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    pair<int, int> S;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        fill(visited[i], visited[i] + M ,-1);
    }

    for (int i = 0; i < N * M; ++i) {
        cin >> map[i / M][i % M];
        if (map[i / M][i % M] == 2)
            S = {i / M, i % M};
        else if (map[i / M][i % M] == 0)
            visited[i / M][i % M] = 0;
    }

    queue<pair<int, int> > Q;
    Q.push(S);
    visited[S.X][S.Y] = 0;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (map[nx][ny] == 0) continue ;
            if (visited[nx][ny] != -1) continue ;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    for (int i = 0; i < N * M; ++i) {
        cout << visited[i / M][i % M];
        if (i % M == M - 1)
            cout << '\n';
        else
            cout << " ";
    }
}