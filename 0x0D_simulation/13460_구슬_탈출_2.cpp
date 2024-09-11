//
// Created by 서정윤 on 2024. 9. 10. 오후 7:18
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, mx = INT32_MAX;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[11][11];
char board_t[11][11];

// 공의 최종 위치를 통해 BFS를 돌리면 공의 최종 위치 visited [red_x][red_y][blue_x][blue_y]별 count를 알 수 있게 된다.
// 나중에 리팩하기

int check_j(int i, int j, int &offset, int dir, bool &is_hole) {
    if (board_t[i][j] == '#') {
        is_hole = false;
        offset = j + dy[dir];
    } else if (board_t[i][j] == 'O') {
        is_hole = true;
    } else if (board_t[i][j] == 'B' || board_t[i][j] == 'R') {
        if (is_hole && board_t[i][j] == 'B') {
            return -1;
        } else if (is_hole && board_t[i][j] == 'R') {
            return 1;
        }
        if (j != offset) {
            board_t[i][offset] = board_t[i][j];
            board_t[i][j] = '.';
        }
        offset += dy[dir];
    }
    return 0;
}

int check_i(int i, int j, int &offset, int dir, bool &is_hole) {
    if (board_t[i][j] == '#') {
        is_hole = false;
        offset = i + dx[dir];
    } else if (board_t[i][j] == 'O') {
        is_hole = true;
    } else if (board_t[i][j] == 'B' || board_t[i][j] == 'R') {
        if (is_hole && board_t[i][j] == 'B') {
            return -1;
        } else if (is_hole && board_t[i][j] == 'R') {
            return 1;
        }
        if (i != offset) {
            board_t[offset][j] = board_t[i][j];
            board_t[i][j] = '.';
        }
        offset += dx[dir];
    }
    return 0;
}

int tilt(int dir) {
    int result;
    int offset;
    bool is_hole;
    bool is_goal = false;
    if (dir == 0) {
        for (int j = 0; j < M; ++j) {
            is_hole = false;
            offset = 0;
            for (int i = 0; i < N; ++i) {
                result = check_i(i, j, offset, dir, is_hole);
                if (result == -1) return result;
                else if (result == 1) is_goal = true;
            }
            if (is_goal) return 1;
        }
    }
    else if (dir == 1) {
        for (int i = 0; i < N; ++i) {
            is_hole = false;
            offset = 0;
            for (int j = 0; j < M; ++j) {
                result = check_j(i, j, offset, dir, is_hole);
                if (result == -1) return result;
                else if (result == 1) is_goal = true;
            }
            if (is_goal) return 1;
        }
    }
    else if (dir == 2) {
        for (int j = M - 1; j >= 0; --j) {
            is_hole = false;
            offset = N - 1;
            for (int i = N - 1; i >= 0; --i) {
                result = check_i(i, j, offset, dir, is_hole);
                if (result == -1) return result;
                else if (result == 1) is_goal = true;
            }
            if (is_goal) return 1;
        }
    }
    else if (dir == 3) {
        for (int i = N - 1; i >= 0; --i) {
            is_hole = false;
            offset = M - 1;
            for (int j = M -1; j >= 0; --j) {
                result = check_j(i, j, offset, dir, is_hole);
                if (result == -1) return result;
                else if (result == 1) is_goal = true;
            }
            if (is_goal) return 1;
        }
    }
//    cout << "[board]\n";
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j) {
//            cout << board_t[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    return 0;
}

void recursive_play(int n) {
    if (n == 10 || n + 1 >= mx) {
        return ;
    }
    char snapshot[11][11];
    int result;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            snapshot[i][j] = board_t[i][j];
        }
    }

    for (int dir = 0; dir < 4; ++dir) {
//        cout << n << ": [원본]\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                board_t[i][j] = snapshot[i][j];
//                cout << board_t[i][j] << ' ';
            }
//            cout << '\n';
        }
//        if (dir == 0)
//            cout << "^\n";
//        else if (dir == 1)
//            cout << "<\n";
//        else if (dir == 2)
//            cout << "v\n";
//        else
//            cout << ">\n";

        result = tilt(dir);
        if (result == -1)
            continue ;
        else if (result == 1) {
            mx = min(mx, n + 1);
//            cout << "mx: " << mx << '\n';
            if (mx == 1) {
                return ;
            }
        }
        recursive_play(n + 1);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N * M; ++i) {
        cin >> board[i/M][i%M];
        board_t[i/M][i%M] = board[i/M][i%M];
    }

    recursive_play(0);
    if (mx == INT32_MAX)
        cout << -1;
    else
        cout << mx;
}