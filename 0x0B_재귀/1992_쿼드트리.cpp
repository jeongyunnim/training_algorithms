//
// Created by 서정윤 on 2024. 8. 29..
//
#include <iostream>

using namespace std;
char input[65][65];
char cur;

void recursive_cut(int num, int x, int y);

void send_each_part(int num, int x, int y) {
    int offset = num / 2;
    for (int i = 0; i < 2; ++i)
        recursive_cut(offset, x + i * offset, y);
    for (int i = 0; i < 2; ++i)
        recursive_cut(offset, x + i * offset, y + offset);
}

void recursive_cut(int num, int x, int y) {
    cur = input[y][x];
    if (num == 1) {
        cout << cur;
        return ;
    }
    for (int i = y; i < y + num; ++i) {
        for (int j = x; j < x + num; ++j) {
            if (cur != input[i][j]) {
                cout << '(';
                send_each_part(num, x, y);
                cout << ')';
                return ;
            }
        }
    }
    cout << cur - '0';
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> input[i][j];
        }
    }
    recursive_cut(N, 0, 0);

    return 0;
}
