//
// Created by 서정윤 on 2024. 11. 4. 오전 1:23
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int N, M, mn = 0x7fffffff;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[51][51];
int visited[51][51];
vector<pair<int ,int> > virus;
queue<pair<int, int> > Q;
int viruses[11];

int BFS() {
    memset(visited, 0xff, sizeof(visited));
    for (int i = 0; i < M; ++i) {
        int cur = viruses[i];
        Q.push(virus[cur]);
        visited[virus[cur].X][virus[cur].Y] = 0;
    }
    int mx = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] > -1 || board[nx][ny] == 1) continue ;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            mx = max(mx, visited[nx][ny]);
            Q.push({nx, ny});
        }
    }
    return mx;
}

bool check() {
    for (int i = 0; i < N * N; ++i) {
        if (visited[i / N][i % N] == -1 && board[i / N][i % N] != 1)
            return false;
    }
    return true;
}

void comb_recur(int n, int cur) {
    if (n == M) {
        int res = BFS();
        if (check())
            mn = min(mn, res);
        return ;
    }
    if (cur < virus.size()) {
        viruses[n] = cur;
        comb_recur(n + 1, cur + 1);
        comb_recur(n, cur + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
        if (board[i / N][i % N] == 2) {
            virus.push_back({i / N, i % N});
        }
    }
    comb_recur(0, 0);
    if (mn == 0x7fffffff)
        mn = -1;
    cout << mn;
}