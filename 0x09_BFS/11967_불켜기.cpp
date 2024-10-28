//
// Created by 서정윤 on 2024. 10. 28. 오후 6:34
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > switches[101][101];
char visited[101][101];
bool lights[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int px, py, tx, ty;
    for (int i = 0; i < M; ++i) {
        cin >> px >> py >> tx >> ty;
        switches[px - 1][py - 1].push_back({tx - 1, ty - 1});
    }
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    // 0 꺼짐 1 켜짐 2 방문
    int cnt = 1;
    visited[0][0] = 2;
    lights[0][0] = 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (auto l : switches[cur.X][cur.Y]) {
            if (lights[l.X][l.Y]) continue ;
            if (visited[l.X][l.Y] == 1) {
                visited[l.X][l.Y] = 2;
                Q.push({l.X, l.Y});
            }
            lights[l.X][l.Y] = 1;
            cnt += 1;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] == 2) continue ;
            if (!lights[nx][ny]) {
                visited[nx][ny] = 1;
                continue ;
            }
            visited[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }
    cout << cnt;
}