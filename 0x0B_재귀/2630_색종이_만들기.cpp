//
// Created by 서정윤 on 2024. 8. 29..
//
#include <iostream>

using namespace std;
char input[129][129];
char cur;
int cnt[2];

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
        cnt[cur - '0'] += 1;
        return ;
    }
    for (int i = y; i < y + num; ++i) {
        for (int j = x; j < x + num; ++j) {
            if (cur != input[i][j]) {
                send_each_part(num, x, y);
                return ;
            }
        }
    }
    cnt[cur - '0'] += 1;
    return ;
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

    cout << cnt[0] << '\n' << cnt[1];
    return 0;
}
