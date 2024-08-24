//
// Created by 서정윤 on 2024. 8. 23..
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define X first
#define Y second

bool cabbage[51][51];
bool visited[51][51];
int dx[4] = {1, 0, -1, 0}; // 오타 잘 보자.. ds[3]이 1이었음.
int dy[4] = {0, 1, 0, -1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, M, N, K;
    int x, y, count;

    queue<pair<int, int> > Q;
    cin >> T;
    while (T--) {
        count = 0;
        Q = queue<pair<int, int> >();
        bzero(cabbage, sizeof(cabbage));
        bzero(visited, sizeof(visited));
        cin >> M >> N >> K;

        for (int i = 0; i < K; ++i) {
            cin >> x >> y;
            cabbage[x][y] = true;
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (cabbage[i][j] && !visited[i][j]) {
                    Q.push({i, j});
                    visited[i][j] = true; // 이 부분이 빠졌었다.
                    count += 1;
                    while (!Q.empty()) {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue ;
                            if (!cabbage[nx][ny] || visited[nx][ny]) continue ;
                            visited[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout << count << '\n';
    }


    return 0;
}