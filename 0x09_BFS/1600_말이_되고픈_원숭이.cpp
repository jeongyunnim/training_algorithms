//
// Created by 서정윤 on 2024. 10. 11. 오후 12:32
//
#include <bits/stdc++.h>

using namespace std;

typedef struct s_info {
    int x;
    int y;
    int m;
} info;

int N, M, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int hx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int hy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
bool board[201][201];
int visited[31][201][201];
queue<info> Q;

int BFS() {
    Q.push({0,0, 0});
    visited[0][0][0] = 1;
    while (!Q.empty()) {
        info cur = Q.front();
        Q.pop();
        if (cur.m < K) {
            for (int i = 0; i < 8; ++i) {
                int nx = cur.x + hx[i];
                int ny = cur.y + hy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (nx == N - 1 && ny == M - 1)
                    return visited[cur.m][cur.x][cur.y];
                if (board[nx][ny]) continue ;
                if (visited[cur.m + 1][nx][ny]) continue ;
                visited[cur.m + 1][nx][ny] = visited[cur.m][cur.x][cur.y] + 1;
                Q.push({nx, ny, cur.m + 1});
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (nx == N - 1 && ny == M - 1)
                return visited[cur.m][cur.x][cur.y];
            if (board[nx][ny]) continue ;
            if (visited[cur.m][nx][ny]) continue; // 조건 추가
            visited[cur.m][nx][ny] = visited[cur.m][cur.x][cur.y] + 1;
            Q.push({nx, ny, cur.m});
        }
//        cout << "[" << cur.m << "]\n";
//        for (int i = 0; i < N * M; ++i) {
//            if (board[i / M][i % M])
//                cout << '*' << ' ';
//            else
//                cout << visited[cur.m][i / M][i % M] << ' ';
//            if (i % M == M - 1) cout << '\n' ;
//        }
//        cout << "[" << cur.m + 1<< "]\n";
//        for (int i = 0; i < N * M; ++i) {
//            if (board[i / M][i % M])
//                cout << '*' << ' ';
//            else
//                cout << visited[cur.m + 1][i / M][i % M] << ' ';
//            if (i % M == M - 1) cout << '\n' ;
//        }

    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> M >> N;
    for (int i = 0; i < N * M; ++i) {
        cin >> board[i / M][i % M];
    }
    if (N + M == 2) {
        cout << 0;
        return 0;
    }

    cout << BFS();
}