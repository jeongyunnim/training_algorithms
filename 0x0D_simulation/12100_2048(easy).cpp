//
// Created by 서정윤 on 2024. 9. 6..
//
#include <iostream>
#include <algorithm>
#define X first
#define Y second

using namespace std;
int N, mx;
int dx[4] = {1,0, -1, 0};
int dy[4] = {0,1, 0, -1};
int board[21][21];
int moved[21][21];

bool is_movable() {
    return false;
}

bool is_moved(int dir) {
    bool move_flag = false;
    if (dir == 2 || dir == 3) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                pair<int, int> cur = make_pair(i, j);
                for (int k = 1; k <= N; ++k) {
                    int nx = cur.X - dx[dir] * k;
                    int ny = cur.Y - dy[dir] * k;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
//                    cout << "(" << cur.X << ',' << cur.Y << "):" << moved[cur.X][cur.Y] << " -> (" << nx << ',' << ny << "): " << moved[nx][ny] << '\n';
                    if (moved[nx][ny] == 0) continue;
                    if (moved[cur.X][cur.Y] == 0 && moved[nx][ny] != 0) {
                        moved[cur.X][cur.Y] = moved[nx][ny];
                        moved[nx][ny] = 0;
                        move_flag = true;
                    } else if (moved[nx][ny] == moved[cur.X][cur.Y]) {
                        moved[cur.X][cur.Y] *= 2;
                        moved[nx][ny] = 0;
                        move_flag = true;

                        break ;
                    } else if (moved[nx][ny] != moved[cur.X][cur.Y]) // 0이 아니면 진행 종료
                        break ;
                }
            }
        }
    }
    else {
        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                pair<int, int> cur = make_pair(i, j);
                for (int k = 1; k <= N; ++k) {
                    int nx = cur.X - dx[dir] * k;
                    int ny = cur.Y - dy[dir] * k;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
//                    cout << "(" << cur.X << ',' << cur.Y << "):" << moved[cur.X][cur.Y] << " -> (" << nx << ',' << ny << "): " << moved[nx][ny] << '\n';
                    if (moved[nx][ny] == 0) continue;
                    if (moved[cur.X][cur.Y] == 0 && moved[nx][ny] != 0) {
                        moved[cur.X][cur.Y] = moved[nx][ny];
                        moved[nx][ny] = 0;
                        move_flag = true;

                    } else if (moved[nx][ny] == moved[cur.X][cur.Y]) {
                        moved[cur.X][cur.Y] *= 2;
                        moved[nx][ny] = 0;
                        move_flag = true;

                        break ; // 합치면 끝
                    } else if (moved[nx][ny] != moved[cur.X][cur.Y]) // 0이 아니면 진행 종료
                        break ;
                }
            }
        }
    }
//    if (dir == 0)
//        cout << "down: ";
//    else if (dir == 1)
//        cout << "right: ";
//    else if (dir == 2)
//        cout << "up: ";
//    else
//        cout << "left: ";
//    cout << "[현황]\n";
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cout << moved[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    if (!move_flag)
        return false;
    else {
        return true;
    }
}

void recursive_move(int n,bool move_flag) {
    int moved_temp[21][21];

    if (!move_flag || n == 5) {

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mx = max(mx, moved[i][j]);
            }
        }
        return ;
    }
    // 현재 상황 temp에 저장
    for (int i = 0; i < N * N; ++i) {
        moved_temp[i/N][i%N] = moved[i/N][i%N];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < N * N; ++j) {
            moved[j/N][j%N] = moved_temp[j/N][j%N]; // 초기화 방향
        }
//        for (int ii = 0; ii < n; ++ii)
//            cout << "  ";
//        cout << n << "번째 기존 소스\n";
//        for (int ii = 0; ii < N; ++ii) {
//            for (int j = 0; j < N; ++j) {
//                cout << moved_temp[ii][j] << ' ';
//            }
//            cout << '\n';
//        }
        if (!is_moved(i)) {
            recursive_move(n + 1, false);
            continue ;
        } else
            recursive_move(n + 1, true);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i/N][i%N];
        moved[i/N][i%N] = board[i/N][i%N];
    }

    recursive_move(0, true);
    cout << mx;

}