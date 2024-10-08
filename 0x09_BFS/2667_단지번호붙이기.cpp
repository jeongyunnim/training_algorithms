//
// Created by 서정윤 on 2024. 10. 8. 오후 4:45
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
queue<pair<int, int> > Q;
vector<int> V;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
char board[26][26];
bool visited[26][26];

void BFS(int x, int y) {
    Q.push({x, y});
    visited[x][y] = true;
    int cnt = 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] || board[nx][ny] == '0') continue ;
            visited[nx][ny] = true;
            cnt += 1;
            Q.push({nx, ny});
        }
    }
    V.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int cnt = 0;
    for (int i = 0; i < N * N; ++i) {
        if (board[i / N][i % N] == '1' && !visited[i / N][i % N]) {
            BFS(i / N, i % N);
            cnt += 1;
        }
    }

    cout << cnt << '\n';
    sort(V.begin(), V.end());
    for (auto el: V) {
        cout << el << '\n';
    }
}