//
// Created by 서정윤 on 2024. 8. 26..
//
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int tomatoes[101][101][101];
int days[101][101][101];

typedef struct s_3d
{
    char x;
    char y;
    char z;
} t_3d;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H;
    queue<t_3d> Q;
    t_3d cur;
    t_3d temp;
    cin >> M >> N >> H;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> tomatoes[i][j][k];
                if (tomatoes[i][j][k] == 1) {
                    cur.x = k;
                    cur.y = j;
                    cur.z = i;
                    Q.push(cur);
                    days[cur.z][cur.y][cur.x] = 1;
                }
            }
        }
    }

    while(!Q.empty()) {
        cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue ;
            if (days[nz][ny][nx] != 0 || tomatoes[nz][ny][nx] == -1) continue ;
            days[nz][ny][nx] = days[cur.z][cur.y][cur.x] + 1;
            temp.x = nx;
            temp.y = ny;
            temp.z = nz;
            Q.push(temp);
        }
    }
    int max = 0;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (days[i][j][k] == 0 && tomatoes[i][j][k] != -1) {
                    cout << -1;
                    return 0;
                }
                else if (max < days[i][j][k]) {
                    max = days[i][j][k];
                }
            }
        }
    }
    cout << max - 1;
    return 0;
}