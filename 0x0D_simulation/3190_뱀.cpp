//
// Created by 서정윤 on 2024. 9. 10. 오후 2:19
//
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second

using namespace std;
queue<pair<int, int> > Q;
pair<int, int> tail, head;
int N, A, L, x, y, sec, dir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, char> moves[100];
int snake[101][101];
char board[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A;

    for (int i = 0; i < A; ++i) {
        cin >> x >> y;
        board[x - 1][y - 1] = 'A';
    }
    cin >> L;
    for (int i = 0; i < L; ++i) {
        cin >> moves[i].X >> moves[i].Y;
    }

    sort(moves, moves + L);

    int play_time = 0;
    dir = 1;
    int move_offset = 0;
    snake[0][0] = true;
    Q.push({0, 0});
    pair<int, char> cur = moves[move_offset];

    while (true) {
        if (play_time == cur.X) {
            if (cur.Y == 'L')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
            move_offset += 1;
            if (move_offset < L)
                cur = moves[move_offset];
        }

        play_time += 1;

        int nx = head.X + dx[dir];
        int ny = head.Y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) break ;
        if (snake[nx][ny]) break ;
        if (board[nx][ny] != 'A') {
            tail = Q.front();
            Q.pop();
            snake[tail.X][tail.Y] = false;
        } else {
            board[nx][ny] = 0;
        }
        snake[nx][ny] = true;
        Q.push({nx, ny});
        head.X = nx;
        head.Y = ny;
//        cout << "[snake]: " << play_time << '\n';
//        for (int i = 0; i < N * N; ++i) {
//            if (board[i/N][i%N] == 'A')
//                cout << "@" << ' ';
//            else
//                cout << snake[i/N][i%N] << ' ';
//            if (i % N == N -1)
//                cout << '\n';
//        }
    }
    cout << play_time;
}
