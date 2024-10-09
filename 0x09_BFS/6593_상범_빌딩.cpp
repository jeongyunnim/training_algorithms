//
// Created by 서정윤 on 2024. 10. 8. 오후 9:51
//
#include <bits/stdc++.h>

using namespace std;
int N, R, C;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
tuple<int, int, int> s;
char building[31][31][31];
int visited[31][31][31];

void BFS() {
    queue<tuple<int, int, int> > Q;

    Q.push(s);
    visited[get<0>(s)][get<1>(s)][get<2>(s)] = 1;
    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            int nz = get<2>(cur) + dz[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= R || nz < 0 || nz >= C) continue ;
            if (visited[nx][ny][nz] != 0 || building[nx][ny][nz] == '#') continue ;
            visited[nx][ny][nz] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            if (building[nx][ny][nz] == 'E') {
                cout << "Escaped in " << visited[nx][ny][nz] - 1 << " minute(s).\n";
                return ;
            }
            Q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> N >> R >> C;
        if (N + R + C == 0) return 0;

//        for (int i = 0; i < 31; ++i) {
//            for (int j = 0; j < 31; ++j) {
//                bzero(building[i][j], 31);
//                bzero(visited[i][j], 31);
//            }
//        }

        cout << "31 * 31 * 31 = " << 31 * 31 * 31 << '\n';
        cout << "4 * 31 * 31 * 31 = " << 4 * 31 * 31 * 31 << '\n';
        cout << "building size: " << sizeof(building) << '\n';
        cout << "visited size: " << sizeof(visited) << '\n';
        bzero(building, sizeof(building));
        bzero(visited, sizeof(visited));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < R; ++j) {
                for (int k = 0; k < C; ++k) {
                    cin >> building[i][j][k];
                    if (building[i][j][k] == 'S')
                        s = make_tuple(i , j , k);
                }
            }
        }

        BFS();

    }
}