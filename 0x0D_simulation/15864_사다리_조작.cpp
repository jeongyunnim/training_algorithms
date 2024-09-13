//
// Created by 서정윤 on 2024. 9. 13. 오후 3:47
//
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int N, M, H, ans = 0x7f7f7f7f;
int board[31][11];
int visited[31][11];
int dx[4] = {0, 0,0};
int dy[4] = {1, 0, -1};

void print_board() {
    cout << "[board]\n";
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool is_match() {
    // 세로 축 확인
    // 마지막 값도 확인해야 함
//    print_board();

    int x, y, pointer;
    for (y = 0; y < N; ++y) {
        pointer = y;
        for (x = 0; x < H; ++x) {
            // x의 값이 도착한 N의 값과 같아야 함.
            if (pointer == 0)
            {
                // 현재만 확인
                if (board[x][pointer]) {
                    pointer += 1;
                }
            }
            else
            {
                //이전 현재 확인
                //  이전 확인
                if (board[x][pointer - 1]) {
                    pointer -= 1;
                }
                //  현재 확인
                else if (board[x][pointer]) {
                    pointer += 1;
                }
            }
        }
//        cout << "세로축: " << y << " -- " << pointer << '\n';
        if (y != pointer)
            return false;
    }
    return true;
}


void recursive_find(int n) {
    if (n == 3) {
        if (ans == 0x7f7f7f7f && is_match()) {
            ans = min(ans, n);
        }
        return ;
    }
    if (is_match()) {
        ans = min(ans, n);
        return ;
    }
    for (int j = 0; j <= N; ++j) {
        for (int i = 0; i < H; ++i) {
            if (board[i][j] || (j > 0 && board[i][j - 1]) || (j < N - 1 && board[i][j + 1])) continue ;
            board[i][j] = true;
            recursive_find(n + 1);
            board[i][j] = false;
            while (i < H) {
                if ((j > 0 && board[i][j - 1]) || (j < N - 1 && board[i][j + 1]))
                    break ;
                i++;
            }
        }
    }
}

int main() {
    int x, y;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        board[x - 1][y - 1] = 2;
    }
    if (M == 0) {
        cout << 0;
        return 0;
    }
    recursive_find(0);
    if (ans == 0x7f7f7f7f)
        ans = -1;
    cout << ans;
}