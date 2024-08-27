//
// Created by 서정윤 on 2024. 8. 27..
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char map[1001][1001];
int fire[1001][1001];
int visited[1001][1001];
int N, W, H;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int> > Q;
    pair<int, int> S;

    cin >> N;
    while (N--) {
        cin >> W >> H;
        bzero(map, sizeof(map));
        bzero(fire, sizeof(fire));
        bzero(visited, sizeof(visited));
        Q = queue<pair<int, int> >();
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> map[j][i];
                if (map[j][i] == '*') {
                    Q.push({j, i});
                    fire[j][i] = 1;
                }
                else if (map[j][i] == '@') {
                    S = {j, i};
                    visited[j][i] = 1;
                }
            }
        }
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue ;
                if (fire[nx][ny] != 0 || map[nx][ny] == '#' || map[nx][ny] == '@') continue ;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        Q.push(S);
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
                    cout << visited[cur.X][cur.Y] << '\n';
                    Q = queue<pair<int, int> >();
                    S = {-1, -1};
                    break ;
                };
                if (visited[nx][ny] != 0 || map[nx][ny] == '#') continue ;
                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                if (fire[nx][ny] != 0 && visited[nx][ny] >= fire[nx][ny]) continue ;
                Q.push({nx, ny});
            }
        }

        if (S.X != -1) {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}