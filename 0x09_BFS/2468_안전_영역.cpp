//
// Created by 서정윤 on 2024. 10. 8. 오후 9:03
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int N;
int board[101][101];
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0 , -1};
bool visited[101][101];

void BFS(int x, int y, int mn) {
    queue<pair<int, int> > Q;
    Q.push({x, y});
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] || board[nx][ny] <= mn) continue ;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int mx = 0;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
        mx = max(board[i / N][i % N], mx);
    }

    int cnt, cnt_max = 0;
    for (int cur = 0; cur <= mx; ++cur) {
        for (int i = 0; i < N; ++i) {
            bzero(visited[i], N);
        }
        cnt = 0;
        for (int i = 0; i < N * N; ++i) {
            int x = i / N, y = i % N;
            if (board[x][y] > cur && !visited[x][y]) {
                BFS(x, y, cur);
                cnt += 1;
            }
        }
        cnt_max = max(cnt, cnt_max);
    }
    cout << cnt_max;
}