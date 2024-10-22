//
// Created by 서정윤 on 2024. 10. 22. 오전 12:34
//
#include <bits/stdc++.h>

typedef struct s_info {
    int x;
    int y;
    int d;
} info;

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, K, ans;
int visited[11][1001][1001];
bool board[1001][1001];
int is_goal = false;
queue<info> Q;

void print_visited(int n) {
    for (int d = 0; d <= n; ++d) {
        cout << "visited[" << d << "]\n";
        for (int i = 0 ; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << visited[d][i][j] << " ";
            }
            cout << '\n';
        }
    }
}

void BFS() {
    Q.push({0, 0, 0});
    // k % 2 == 0 아침 & k % 2 == 1 저녁
    visited[0][0][0] = 1;
    while (!Q.empty()) {
        info cur = Q.front();
        int cur_val = visited[cur.d][cur.x][cur.y];
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (visited[cur.d][nx][ny] && visited[cur.d][nx][ny] <= cur_val + 1) continue ;
            if (nx == N - 1 && ny == M - 1) {
                is_goal = true;
            }
            if (board[nx][ny]) {
                // 밤이면 하루 더 기다려야 함.
                if (cur.d < K) {
                    if (cur_val % 2 && (visited[cur.d + 1][nx][ny] == 0 || visited[cur.d + 1][nx][ny] > cur_val + 1))
                        visited[cur.d + 1][nx][ny] = cur_val + 1;
                    else if (visited[cur.d + 1][nx][ny] == 0 || visited[cur.d + 1][nx][ny] > cur_val + 2)
                        visited[cur.d + 1][nx][ny] = cur_val + 2;
                    else
                        continue ;
                    Q.push({nx, ny, cur.d + 1});
                }
                continue ;
            }
            visited[cur.d][nx][ny] = visited[cur.d][cur.x][cur.y] + 1;
            Q.push({nx, ny, cur.d});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    char c;
    for (int i = 0; i < N * M; ++i) {
        cin >> c;
        if (c == '1')
            board[i / M][i % M] = true;
    }
    if (N * M == 1) {
        cout << 1;
        return 0;
    }

    BFS();
//    print_visited(K);
    if (is_goal) {
        int mn = 0x7fffffff;
        for (int i = 0 ; i <= K; ++i) {
            if (visited[i][N - 1][M - 1])
                mn = min(mn, visited[i][N - 1][M - 1]);
        }
        cout << mn;
    } else
        cout << -1;
}
