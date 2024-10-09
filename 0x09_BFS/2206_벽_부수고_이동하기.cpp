//
// Created by 서정윤 on 2024. 10. 9. 오후 3:13
//
#include <bits/stdc++.h>

using namespace std;
int N, M, min = numeric_limits<int>::max();
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct s_info {
    int x;
    int y;
    int is_break;
} info;

queue<info> Q;
char board[1001][1001];
int visited[1001][1001][2];

void print_visited(bool is_break) {
    cout << "[visited] - " << is_break << '\n';
    for (int i = 0; i < N * M; ++i) {
        cout << visited[i / M][i % M][is_break] << " ";
        if (i % M == M - 1) cout << '\n';
    }
}

void BFS() {
    Q.push({0,0});
    visited[0][0][0] = 1;
    while (!Q.empty()) {
        info cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny][cur.is_break] != 0) continue ;
            if (nx == N - 1 && ny == M - 1) {
                cout << visited[cur.x][cur.y][cur.is_break] + 1;
                return ;
            }
            if (board[nx][ny] == '1') {
                if (cur.is_break == 1)
                    continue ;
                visited[nx][ny][1] = visited[cur.x][cur.y][0] + 1;
//                cout << "부수었다: " << nx << ", " << ny << '\n';
                Q.push({nx, ny, 1});
//                print_visited(1);
            } else {

                visited[nx][ny][cur.is_break] = visited[cur.x][cur.y][cur.is_break] + 1;
//                cout << "안 부수었다.: " << nx << ", " << ny << '\n';
                Q.push({nx, ny, cur.is_break});
//                print_visited(cur.is_break);
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N * M; ++i) {
        cin >> board[i / M][i % M];
    }
    if (N + M == 2)
        cout << 1;
    else
        BFS();
}