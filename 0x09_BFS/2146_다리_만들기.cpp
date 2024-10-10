//
// Created by 서정윤 on 2024. 10. 10. 오후 3:36
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int N, mn = numeric_limits<int>::max();
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int visited[101][101];
queue<pair<int, int> > Q;
queue<pair<int, int> > startQ;

void mark_ground(int x, int y, int num) {
    Q.push({x, y});
    visited[x][y] = num;
    board[x][y] = num;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] == 1) continue ;
            if (board[nx][ny] == 0) {
                startQ.push({nx, ny});
                continue ;
            }
            board[nx][ny] = num;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

void find_ground() {
    int num = 1;
    for (int i = 0; i < N * N; ++i) {
        int x = i / N;
        int y = i % N;
        if (!board[x][y] || visited[x][y]) continue ;
        mark_ground(x, y, num++);
    }
}

void connect_ground() {
    while (!startQ.empty()) {
        Q = queue<pair<int, int> >();
        Q.push(startQ.front());
        startQ.pop();
        bzero(visited, sizeof(visited));
        visited[Q.front().X][Q.front().Y] = 1;
        int current_num = 0;
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
                if (visited[nx][ny] > 0) continue ;
                if (board[nx][ny] != 0) {
                    if (current_num == 0)
                        current_num = board[nx][ny];
                    else if (current_num == board[nx][ny])
                        continue ;
                    else {
                        mn = min(mn, visited[cur.X][cur.Y]);
                        break ;
                    }
                } else {
                    visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
            }
            if (visited[cur.X][cur.Y] >= mn)
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
    }
    find_ground();
    connect_ground();
    cout << mn;
}