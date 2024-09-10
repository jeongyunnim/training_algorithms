//
// Created by 서정윤 on 2024. 9. 10. 오후 3:29
//
#include <iostream>
#include <algorithm>

int N, M, mx;
int board[500][500];

using namespace std;

int check_first(int x, int y) {
    int area1 = 0;
    int area2 = 0;

    if (x + 3 < N) {
        for (int i = 0; i < 4; ++i) {
            area1 += board[x + i][y];
        }
    }
    if (y + 3 < M) {
        for (int i = 0; i < 4; ++i) {
            area2 += board[x][y + i];
        }
    }
    return max(area1, area2);
}

int check_second(int x, int y) {
    int area = 0;

    if (x + 1 >= N || y + 1 >= M) {
        return 0;
    }
    for (int i = 0; i < 2; ++i) {
        area += board[x][y + i];
        area += board[x + 1][y + i];
    }
    return area;
}

int check_third(int x, int y) {
    int cur_mx = 0;
    int area1 = 0;
    int area2 = 0;
    if (x + 1 < N && y + 2 < M) {
        for (int i = 0; i < 3; ++i) {
            area1 += board[x][y + i];
        }
        area1 += max({board[x + 1][y], board[x + 1][y + 1], board[x + 1][y + 2]});
        for (int i = 0; i < 3; ++i) {
            area2 += board[x + 1][y + i];
        }
        area2 += max({board[x][y], board[x][y + 1], board[x][y + 2]});
        cur_mx = max(area1, area2);
        area1 = 0;
        area2 = 0;
    }
    if (x + 2 < N && y + 1 < M) {
        for (int i = 0; i < 3; ++i) {
            area1 += board[x + i][y];
        }
        area1 += max({board[x][y + 1], board[x + 1][y + 1], board[x + 2][y + 1]});
        for (int i = 0; i < 3; ++i) {
            area2 += board[x + i][y + 1];
        }
        area2 += max({board[x][y], board[x + 1][y], board[x + 2][y]});
    }
    return max({cur_mx, area1, area2});
}

int check_fourth(int x, int y) {
    int area1 = 0;
    int area2 = 0;
    if (x + 1 < N && y + 2 < M) {
        area1 = max(board[x][y] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y + 2], \
                    board[x][y + 1] + board[x][y + 2] + board[x + 1][y] + board[x + 1][y + 1]);
    }
    if (x + 2 < N && y + 1 < M) {
        area2 = max(board[x][y] + board[x + 1][y] + board[x + 1][y + 1] + board[x + 2][y + 1], \
                    board[x + 1][y] + board[x + 2][y] + board[x][y + 1] + board[x + 1][y + 1]);
    }
//    cout << "area: " << area1 << ", " << area2 << '\n';
    return max(area1, area2);
}

void BFS() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            mx = max({mx, check_first(i, j), check_second(i, j),check_third(i, j),check_fourth(i, j)});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    BFS();
    cout << mx;
}