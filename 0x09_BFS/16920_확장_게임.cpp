//
// Created by 서정윤 on 2025. 1. 25. 오전 10:51
//
#include <bits/stdc++.h>

using namespace std;
int N, M, P;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int> > Q[10]; // x y life
char board[1001][1001];
int visited[1001][1001]; // 플레이어 성
int player[10]; // 플레이어의 이동 가능 횟수
int ans[10]; // 플레이어의 성 개수

bool BFS(int p) {
    int is_moved = false;
    int size = Q[p].size();

    while (size--) {
        int x, y, life;
        tie(x, y, life) = Q[p].front();
        Q[p].pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (visited[nx][ny] || board[nx][ny] != '.') continue ;
            visited[nx][ny] = p;
            ans[p] += 1;
            is_moved = true;
            if (life != 1) {
                Q[p].push({nx, ny, life - 1});
                size += 1;
            }
            else
                Q[p].push({nx, ny, player[p]});
        }
    }
    return is_moved;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; ++i) {
        cin >> player[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (isdigit(board[i][j])) {
                int p = board[i][j] - '0';
                Q[p].push({i, j, player[p]});
                ans[p] += 1;
                visited[i][j] = p;
            }
        }
    }
    while (1) {
        int move_flag = 0;
        for (int i = 1; i <= P; ++i) {
            move_flag += BFS(i);
        }
        if (!move_flag)
            break ;
    }

    for (int i = 1; i <= P; ++i) {
        cout << ans[i] << ' ';
    }
}