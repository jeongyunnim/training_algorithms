//
// Created by 서정윤 on 2024. 8. 22.
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
char input[1001][1001];
int fire[1001][1001];
int route[1001][1001];
queue<pair<int, int> > Q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    pair<int, int> J;
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; j++) {
            if (input[i][j] == 'F') {
                Q.push({i, j});
                fire[i][j] = 1;
            }
            else if (input[i][j] == 'J') {
                J = {i, j};
                route[i][j] = 1;
            }
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue ;
            if (input[nx][ny] == '#' || input[nx][ny] == 'J' || fire[nx][ny] != 0) continue ;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    Q.push(J);
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << route[cur.X][cur.Y];
                return 0;
            }
            if (input[nx][ny] == '#' || input[nx][ny] == 'F' || route[nx][ny] != 0) continue ;

            route[nx][ny] = route[cur.X][cur.Y] + 1; // 먼저 더해준 뒤 검사
            if (fire[nx][ny] != 0 && route[nx][ny] >= fire[nx][ny]) continue ; // 0은 불이 번지지 않았으므로 pass
            Q.push({nx, ny});
        }
    }

//    cout << "\n[route check]\n";
//    for (int j = 0; j < R; ++j) {
//        for (int k = 0; k < C; ++k) {
//            cout << route[j][k];
//        }
//        cout << '\n';
//    }
//    cout << "\n[fire check]\n";
//    for (int j = 0; j < R; ++j) {
//        for (int k = 0; k < C; ++k) {
//            cout << fire[j][k];
//        }
//        cout << '\n';
//    }

    cout << "IMPOSSIBLE\n";

    return 0;
}