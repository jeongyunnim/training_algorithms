//
// Created by 서정윤 on 2024. 8. 30..
//
#include <iostream>

using namespace std;

int input[21];
int seq[21];
bool issued[21];
int N, S, cnt;

void recursive_sum(int cur, int total) {
    if (cur == N) {
        if (S == total)
            cnt += 1;
        return ;
    }
    recursive_sum(cur + 1, total);
    recursive_sum(cur + 1, total + input[cur]);
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    recursive_sum(0, 0);
    if (S == 0)
        cnt -= 1;
    cout << cnt;
    return 0;
}