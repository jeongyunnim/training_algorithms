//
// Created by 서정윤 on 2024. 8. 30..
//
#include <iostream>

using namespace std;

int N, M;
int seq[9];
bool issued[9];

void recursive_find(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i]  << ' ';
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= N; ++i) {
        if (!issued[i]) {
            seq[cur] = i;
            issued[i] = true;
            recursive_find(cur + 1);
            issued[i] = false;
        }
    }
}

int main() {

    cin >> N >> M;

    recursive_find(0);
    return 0;
}