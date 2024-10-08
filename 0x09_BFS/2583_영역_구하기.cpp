//
// Created by 서정윤 on 2024. 10. 8. 오후 4:07
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector<int> V;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K;
int cnt, ans;
bool board[101][101];

int BFS(int x, int y) {
    queue<pair<int, int> > Q;
    int space = 1;
    Q.push({x, y});
    board[x][y] = true;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (board[nx][ny]) continue ;
            board[nx][ny] = true;
            space += 1;
            Q.push({nx, ny});
        }
    }
    return space;
}

void solve() {
    for (int i = 0; i < M * N; ++i) {
        if (!board[i / M][i % M]) {
            V.push_back(BFS(i / M, i % M));
            cnt += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int j = sx; j < ex; ++j) {
            for (int k = sy; k < ey; ++k) {
                board[j][k] = true;
            }
        }
    }

    solve();
    cout << cnt << '\n';
    sort(V.begin(), V.end());
    for (auto el: V) {
        cout << el << " ";
    }
}