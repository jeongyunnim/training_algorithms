//
// Created by 서정윤 on 8/17/24.
//
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MAX_VAL 1002
int board[MAX_VAL][MAX_VAL];
int tomato[MAX_VAL][MAX_VAL];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue< pair<int, int> > Q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
                tomato[i][j] = 0;
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i=0;i<4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == -1 || tomato[nx][ny] != 0) continue;
            tomato[nx][ny] = tomato[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int mx = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            mx = max(mx, tomato[i][j]);
        }
    }
    cout << mx;
    return 0;
}