//
// Created by 서정윤 on 2024. 8. 30..
//
#include <iostream>

using namespace std;
int N, cnt;
int board[16];

bool is_dup(int cur, int target) {
    for (int i = 0; i < cur; ++i) {
        if (target == board[i] || target == board[i] - cur + i || target == board[i] + cur - i)
            return true;
    }
    return false;
}

void recursive_find(int cur) {

    if (cur == N) {
        cnt++;
        return ;
    }

    for (int i = 0; i < N; ++i) {
        if (is_dup(cur, i))
            continue ;
        board[cur] = i;
        recursive_find(cur + 1);
        board[cur] = -1;
    }
}

int main() {
    cin >> N;

    recursive_find(0);
    cout << cnt;
    return 0;
}