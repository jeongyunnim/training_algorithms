//
// Created by 서정윤 on 2024. 10. 9. 오후 7:26
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int glacier[301][301];
bool visited[301][301];
queue<pair<int, int> > Q;
int N, M;

bool melt() {
    bool is_melt = false;
    int temp[301][301];

    memcpy(temp, glacier, sizeof(glacier));
    for (int i = 0; i < N * M; ++i) {
        int x = i / M;
        int y = i % M;
        if (glacier[x][y] == 0) continue ;
        for (int j = 0; j < 4; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (glacier[nx][ny] == 0) {
                temp[x][y] -= 1;
                is_melt = true;
            }
        }
        if (temp[x][y] < 0) temp[x][y] = 0;
    }
    memcpy(glacier, temp, sizeof(glacier));
//    cout << "[melted]\n";
//    for (int i = 0; i < N * M; ++i) {
//        int x = i / M;
//        int y = i % M;
//        cout << glacier[x][y] << " ";
//        if (y == M - 1) cout << '\n';
//    }
    return is_melt;
}

int check_cnt() {
    int cnt = 0;
    bzero(visited, sizeof(visited));
    for (int i = 0; i < N * M; ++i) {
        int x = i / M;
        int y = i % M;
        if (glacier[x][y] == 0 || visited[x][y]) continue ;
        Q.push({x, y});
        cnt += 1;
        visited[x][y] = true;
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
                if (glacier[nx][ny] == 0 || visited[nx][ny]) continue ;
                visited[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
//    cout << "[visited]\n";
//    for (int i = 0; i < N * M; ++i) {
//        int x = i / M;
//        int y = i % M;
//        cout << visited[x][y] << " ";
//        if (y == M - 1) cout << '\n';
//    }
    return cnt;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N * M; ++i) {
        cin >> glacier[i / M][i % M];
    }
    int time = 0;
    while (true) {
        time += 1;
        bool is_melt = melt();
        if (check_cnt() > 1)
            break ;
        if (!is_melt) {
            time = 0;
            break ;
        }
    }
    cout << time;
}
