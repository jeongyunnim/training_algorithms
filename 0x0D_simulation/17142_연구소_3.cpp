//
// Created by 서정윤 on 2024. 11. 13. 오후 4:30
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > virus;
int N, M, mn = 0x7fffffff;
int visited[51][51];
int comb[11];
char board[51][51];

void print() {
    for (int i = 0; i < M; ++i) {
        cout << "(" << virus[comb[i]].X << ", " << virus[comb[i]].Y << "), ";
    }
    cout << '\n';
    for (int i = 0; i < N * N; ++i) {
        if (board[i / N][i % N] == '1')
            cout << "- ";
        else
            cout << visited[i / N][i % N] << " ";
        if (i % N == N - 1) cout << '\n';
    }
}

int BFS() {
    queue<pair<int, int> > Q;
    int mx = 0;

    memset(visited, 0xff, sizeof(visited));
    for (int i = 0; i < M; ++i) {
        Q.push(virus[comb[i]]);
        visited[virus[comb[i]].X][virus[comb[i]].Y] = 0;
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (board[cur.X][cur.Y] != '2')
            mx = max(mx, visited[cur.X][cur.Y]);
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] != -1|| board[nx][ny] == '1') continue ;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
//    cout << "mx]" << mx << '\n';
//    print();
    for (int i = 0; i < N * N; ++i) {
        if (board[i / N][i % N] == '0' && visited[i / N][i % N] == -1)
            return -1;
    }
    return mx;
}

void solve(int n, int cur) {
    if (n == M) {
        int res = BFS();
        if (res != -1)
            mn = min(mn, res);
        return ;
    }

    comb[n] = cur;
    if (cur < virus.size()) {
        solve(n + 1, cur + 1);
        solve(n, cur + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
        if (board[i / N][i % N] == '2') {
            virus.push_back({i / N, i % N});
        }
    }
    solve(0, 0);
    if (mn == 0x7fffffff)
        cout << -1;
    else
        cout << mn;
}