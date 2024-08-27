//
// Created by 서정윤 on 2024. 8. 27..
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define X first
#define Y second

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, -2, 2, 1, -1};
int visited[301][301];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, I, x, y;
    queue<pair<int, int> > Q;
    cin >> N;

    while (N--) {
        cin >> I;
        cin >> x >> y;
        Q.push({x, y});
        visited[x][y] = 1;
        cin >> x >> y;
        if (Q.front().X == x && Q.front().Y == y) {
            cout << "0\n";
            Q.pop();
        }
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 8; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (x == nx && y == ny) {
                    cout << visited[cur.X][cur.Y] << '\n';
                    Q = queue<pair<int, int> >();
                    break ;
                }
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue ;
                if (visited[nx][ny] != 0) continue ;
                visited[nx][ny] = visited[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        bzero(visited, sizeof(visited));
    }
    return 0;
}