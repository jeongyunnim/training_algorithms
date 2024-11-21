//
// Created by 서정윤 on 2024. 11. 21. 오후 3:30
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
deque<pair<int, int> > edges;
int distances[11][11];
int comb[11];
int N, M, cnt;
int visited[21][21];
char board[21][21];
bool is_used[11];

void print_visited() {
    cout << "[visited]\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] < 11)
                cout << "* ";
            else if (visited[i][j] == -1)
                cout << "- ";
            else
                cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "[distances]\n";
    for (int i = 0; i < edges.size(); ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            cout << distances[i][j] << " ";
        }
        cout << '\n';
    }
}

bool BFS(int start) {
    queue<pair<int, int> > Q;
    int flag = edges.size() - 1;

    if (start)
        flag -= 1;
    memset(visited, -1, sizeof(visited));
    Q.push(edges[start]);
    visited[edges[start].X][edges[start].Y] = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (visited[nx][ny] != -1 || board[nx][ny] == 'x') continue ;
            if (board[nx][ny] < 11) {
                flag -= 1;
                distances[start][board[nx][ny]] = visited[cur.X][cur.Y] + 1;
                distances[board[nx][ny]][start] = visited[cur.X][cur.Y] + 1;
                if (flag == 0)
                    return true;
            }
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    return false;
}

void recursive_comb(int n) {
    if (n == edges.size()) {
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += distances[comb[i - 1]][comb[i]];
        }
        cnt = min(cnt, res);
        return ;
    }
    for (int i = 1; i < edges.size(); ++i) {
        if (is_used[i]) continue ;
        is_used[i] = true;
        comb[n] = i;
        recursive_comb(n + 1);
        is_used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> M >> N;
        if (N + M == 0) break ;
        memset(board, 0, sizeof(board));
        memset(is_used, 0, sizeof(is_used));
        edges.clear();
        cnt = 0x7fffffff;
        int dust_i = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> board[i][j];
                if (board[i][j] == '*') {
                    edges.push_back({i, j});
                    board[i][j] = dust_i++;
                } else if (board[i][j] == 'o') {
                    edges.push_front({i, j});
                    board[i][j] = '.';
                }
            }
        }
        int is_reachable = true;
        for (int i = 0; i < edges.size(); ++i) {
            if (!BFS(i)) {
                is_reachable = false;
                break ;
            }
//            print_visited();
        }
        if (is_reachable) {
            comb[0] = 0;
            recursive_comb(1);
            cout << cnt << '\n';
        } else
            cout << "-1\n";
    }
}
