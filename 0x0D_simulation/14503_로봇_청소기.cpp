//
// Created by 서정윤 on 2024. 9. 10. 오후 1:06
//
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

enum {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

queue<pair<int, int> > Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, x, y, dir, total;
bool room[51][51];
bool visited[51][51];

/*
    1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
        2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
    3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
        3-1. 반시계 방향으로 90도 회전한다.
        3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        3-3. 1번으로 돌아간다.
*/
void BFS() {
    bool move_flag;
    Q.push({x, y});
    visited[x][y] = 1;
    total += 1;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        move_flag = false;
        for (int i = 0; i < 4; ++i) {
           int nx = cur.X + dx[(dir - i + 3) % 4];
           int ny = cur.Y + dy[(dir - i + 3) % 4];
           if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
           if (room[nx][ny]) continue ;
           if (!visited[nx][ny]) {
               visited[nx][ny] = true;
               total += 1;
               Q.push({nx, ny});
               dir = (dir - i + 3) % 4;
               move_flag = true;
               break ;
           }
        }
        if (!move_flag) {
            int nx = cur.X + dx[(dir + 2) % 4];
            int ny = cur.Y + dy[(dir + 2) % 4];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) return ;
            if (room[nx][ny]) return ;
            Q.push({nx, ny});
        }
//        cout << "\n[visited]\n";
//        for (int i = 0; i < N; ++i) {
//            for (int j = 0; j < M; ++j) {
//                if (room[i][j])
//                    cout << '-' << ' ';
//                else
//                    cout << visited[i][j] << ' ';
//            }
//            cout << '\n';
//        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> x >> y >> dir;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> room[i][j];
        }
    }
    BFS();
    cout << total;


}