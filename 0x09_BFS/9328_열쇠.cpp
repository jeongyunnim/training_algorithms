//
// Created by 서정윤 on 2024. 10. 30. 오후 2:21
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > entry_points;
vector<pair<int, int> > closed_doors;
char board[101][101];
bool visited[101][101];
bool alpha[26];
bool meet_key = false;
string key;
int T, N, M;
int cnt;

bool is_pass(char c) {
    if (islower(c)) {
        alpha[c - 'a'] = true;
    } else if (!alpha[c - 'A']) {
        return false ;
    }
    return true;
}

void BFS(int x, int y) {
    if (isalpha(board[x][y]) && !is_pass(board[x][y])) {
        closed_doors.push_back({x, y});
        return ;
    }
    if (board[x][y] == '$')
        cnt += 1;
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visited[x][y] = 1;
    board[x][y] = '.';
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (visited[nx][ny] || board[nx][ny] == '*') continue ;
            if (board[nx][ny] == '$') {
                cnt += 1;
            } else if (isalpha(board[nx][ny]) && !is_pass(board[nx][ny])) {
                visited[nx][ny] = 1;
                closed_doors.push_back({nx, ny});
                continue ;
            }
            board[nx][ny] = '.';
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

bool check_open() {
    bool is_open = false;
    for (int i = 0; i < closed_doors.size(); ++i) {
        int x = closed_doors[i].X;
        int y = closed_doors[i].Y;
        if (isupper(board[x][y]) && is_pass(board[x][y])) {
            BFS(x, y);
            is_open = true;
        }
    }
    // 해당 벡터를 다루는 반복문 안에서 벡터의 요소가 추가 되는 경우
    for (auto it = closed_doors.begin(); it != closed_doors.end();) {
        if (board[it->X][it->Y] == '.') {
            it = closed_doors.erase(it);
        } else {
            ++it;
        }
    }
    return is_open;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        cnt = 0;
        bzero(alpha, sizeof(alpha));
        bzero(visited, sizeof(visited));
        closed_doors.clear(); // dumb..
        entry_points.clear();
        for (int i = 0; i < N * M; ++i) {
            cin >> board[i / M][i % M];
            if ((i / M == 0 || i / M == N - 1 || i % M == 0 || i % M == M - 1) && board[i / M][i % M] != '*')
                entry_points.push_back({i / M, i % M});
        }
        cin >> key;
        if (!key.empty() && key[0] != '0') {
            for (int i = 0; i < key.size(); ++i) {
                alpha[key[i] - 'a'] = true;
            }
        }
        for (auto p : entry_points)
            BFS(p.X, p.Y);
        while (check_open());
        cout << cnt << '\n';
    }
}
