//
// Created by 서정윤 on 2024. 11. 28. 오후 3:49
//
#include <bits/stdc++.h>

using namespace std;
class info {
public:
    info(int x, int y, int t, char ch) {
        _x = x;
        _y = y;
        _t = t;
        _str = ch;
    }
    info(int x, int y, int t, string str) {
        _x = x;
        _y = y;
        _t = t;
        _str = str;
    }
    int _x, _y, _t;
    string _str;
};

map<string, int> cases;
int N, M, K;
char board[11][11];

void DFS(int x, int y) {
    queue<info> Q;
    int dx[8] = {1, 1, 1, 0, 0, N - 1, N - 1, N - 1};
    int dy[8] = {M - 1, 0, 1, M - 1, 1, M - 1, 0, 1};

    Q.push({x, y, 1, board[x][y]});
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        cases[cur._str] += 1;
        if (cur._t == 5)
            continue ;
        for (int i = 0; i < 8; ++i) {
            int nx = (cur._x + dx[i]) % N;
            int ny = (cur._y + dy[i]) % M;
            Q.push({nx, ny, cur._t + 1, cur._str + board[nx][ny]});
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            DFS(i, j);
        }
    }
    for (int i = 0; i < K; ++i) {
        string query;
        cin >> query;
        cout << cases[query] << '\n';
    }
}