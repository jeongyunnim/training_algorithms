//
// Created by 서정윤 on 2024. 8. 31..
//
#include <iostream>

using namespace std;
int N, M;
int seq[8];

void recursive_compose(int n) {
    if (n == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= N; ++i) {
        if (n != 0 && seq[n-1] > i)
            continue ;
        seq[n] = i;
        recursive_compose(n + 1);
    }
}

int main() {
    cin >> N >> M;

    recursive_compose(0);

    return 0;
}