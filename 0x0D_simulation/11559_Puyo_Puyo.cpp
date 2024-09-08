//
// Created by 서정윤 on 2024. 9. 8..
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define X first
#define Y second

using namespace std;

queue<pair<int, int> > Q;
int N = 12, M = 6, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[13][7];
bool visited[13][7];

void pop_puyo() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j]) {
                board[i][j] = '.';
            }
        }
    }

}

void next_combo() {
    for (int i = N - 1; i >= 0; --i) {
        for (int j = M - 1; j >= 0; --j) {
            if (board[i][j] == '.') {
                for (int k = 1; k <= N; ++k) {
                    int nx = i + dx[2] * k;
                    int ny = j + dy[2] * k;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) break ;
                    if (board[nx][ny] == '.') continue ;
                    else {
                        board[i][j] = board[nx][ny];
                        board[nx][ny] = '.';
                        break ;
                    }
                }
            }
        }
    }
}

bool check_adj_four(int x, int y) {
    int puyo_cnt = 1;
    char c = board[x][y];

    for (int i = 0; i < N; ++i) {
        bzero(visited[i], sizeof(visited[i]));
    }
    Q.push({x, y});
    visited[x][y] = 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (board[nx][ny] != c) continue ;
            if (visited[nx][ny] != 0) continue ;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
            puyo_cnt += 1;
        }
    }
    if (puyo_cnt >= 4) {
        return true;
    }
    return false;
}

void find_puyo() {
    bool pop_flag = true;
    while (pop_flag) {
        pop_flag = false;
        for (int i = N - 1; i >= 0; --i) {
            for (int j = M - 1; j >= 0; --j) {
                if (board[i][j] == '.') continue ;
                if (check_adj_four(i, j)) {
                    pop_puyo();
                    pop_flag = true;
                }
            }
        }
        if (pop_flag) {
            next_combo();
            cnt += 1;
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    find_puyo();
    cout << cnt;
}