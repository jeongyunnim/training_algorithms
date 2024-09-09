//
// Created by 서정윤 on 2024. 9. 9.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct s_3d {
    int x, y, z;
} t_3d;

bool map[5][5][5];
int visited[5][5][5];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int maze[5]; // 맵 번호
int is_used[5];
int mn = INT32_MAX;

void rotate(int num) {
    bool temp[5][5];

    for (int i = 0; i < 25; ++i) {
        temp[i/5][i%5] = map[num][i/5][i%5];
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            map[num][i][j] = temp[j][5 - 1 - i];
        }
    }
}

bool is_available(int num, int order) {
    if (order == 0 && !map[num][0][0])
        return false;
    else if (order == 4 && !map[num][4][4])
        return false;
    else
        return true;
}

void BFS() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            bzero(visited[i][j], sizeof(visited[i][j]));
        }
    }
    queue<t_3d> Q;
    t_3d temp;

    temp.x = 0;
    temp.y = 0;
    temp.z = 0;

    Q.push(temp);
    visited[0][0][0] = 1;
    while (!Q.empty()) {
        t_3d cur = Q.front(); Q.pop();
        for (int i = 0; i < 6; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue ;
            if (!map[maze[nx]][ny][nz]) continue ;
            if (visited[nx][ny][nz] != 0) continue ;
            visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] + 1;
            if (nx + ny + nz == 12) return ;
            temp.x = nx;
            temp.y = ny;
            temp.z = nz;
            Q.push(temp);
        }
    }
}

void recursive_comb(int n) {
    if (n == 5) {
        BFS();
        if (visited[4][4][4])
            mn = min(mn, visited[4][4][4]);
        return ;
    }
    for (int i = 0; i < 5; ++i) {
        if (is_used[i]) continue ;
        is_used[i] = true;
        for (int j = 0; j < 4; ++j) {
            if (is_available(i, n)) {
                maze[n] = i;
                recursive_comb(n + 1);
            }
            rotate(i);
        }
        is_used[i] = false;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> map[i][j][k];
            }
        }
    }
    recursive_comb(0);
    if (mn == INT32_MAX)
        cout << -1;
    else
        cout << mn - 1;
}