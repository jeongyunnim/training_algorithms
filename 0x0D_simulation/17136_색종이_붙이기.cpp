//
// Created by 서정윤 on 2025. 2. 2. 오후 3:34
//
#include <bits/stdc++.h>

using namespace std;
int board[11][11];
int visited[11][11];
int sticker[6] = {0,5, 5, 5, 5, 5};
int cur;
int mn = -1;

void fill_square(int x, int y, int size, int fill) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[x + i][y + j] = fill;
        }
    }
}

bool check() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool print() {
    cout << "print]\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(3) << board[i][j];
        }
        cout << '\n';
    }
    return true;
}


void find_next(int &x, int &y) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] == 1) {
                x = i;
                y = j;
                return ;
            }
        }
    }
    x = 10;
    y = 10;
    return ;
}

void solve() {
    int x, y;

    find_next(x, y);
    if (x == 10 && y == 10) {

        if (mn == -1 || mn > cur) {
            mn = cur;
        }
        return ;
    }
    //find max
    int mx_sz = 5;
    int i = 0;
    int j = 0;
    for (; i < mx_sz; ++i) {
        if (!board[x + i][y])
            break ;
        for (j = 0; j < mx_sz; ++j) { // j를 0으로 초기화 해주지 않았었다.
            int nx = x + i;
            int ny = y + j;
            if (nx >= 10 || ny >= 10 || board[nx][ny] != 1) {
                mx_sz = min(mx_sz, j);
                break ;
            }
        }
    }
    mx_sz = min({mx_sz, i, j});
    while (mx_sz) {
        if (!sticker[mx_sz]) {
            mx_sz -= 1;
            continue;
        }
        if (mn != -1 && mn == cur) {
            return ;
        }
        fill_square(x, y, mx_sz, mx_sz * 11);
        cur += 1;
        sticker[mx_sz] -= 1;
        solve();
        cur -= 1;
        sticker[mx_sz] += 1;
        fill_square(x, y, mx_sz, 1);
        mx_sz -= 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> board[i][j];
        }
    }
    solve();
    cout << mn;
}