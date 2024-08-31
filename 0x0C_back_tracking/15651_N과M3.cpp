//
// Created by 서정윤 on 2024. 8. 30..
//
#include <iostream>

using namespace std;

int N, M;
int seq[9];

void recursive_find(int cur, int ptr) {
    if (cur == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= N; ++i) {
        seq[cur] = i;
        recursive_find(cur + 1, i);
    }
}

int main() {

    cin >> N >> M;

    recursive_find(0, 1);
    return 0;
}