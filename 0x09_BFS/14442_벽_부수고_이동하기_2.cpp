//
// Created by 서정윤 on 2024. 10. 11. 오후 12:32
//
#include <bits/stdc++.h>

using namespace std;

/*

6 4 1
0000
1110
1000
0000
0111
0000

 */

typedef struct s_info {
    int x;
    int y;
    int m;
} info;

int N, M, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[1001][1001];
int visited[11][1001][1001];
queue<info> Q;

void BFS() {
    Q.push({0,0, 0});
    visited[0][0][0] = 1;
    while (!Q.empty()) {
        info cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int move = cur.m;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (nx == N - 1 && ny == M - 1) {
                cout << visited[cur.m][cur.x][cur.y] + 1;
                return ;
            }
            if (board[nx][ny] == '1') {
                if (move >= K) continue ;
                move += 1;
            }
            if (visited[move][nx][ny]) continue; // 조건 추가
            visited[move][nx][ny] = visited[cur.m][cur.x][cur.y] + 1;
            Q.push({nx, ny, move});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N * M; ++i) {
        cin >> board[i / M][i % M];
    }
    if (N + M == 2) {
        cout << 1;
        return 0;
    }

    BFS();
}