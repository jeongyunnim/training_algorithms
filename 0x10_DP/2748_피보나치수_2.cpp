//
// Created by 서정윤 on 2024. 9. 26. 오후 8:30
//
#include <iostream>

using namespace std;

long long seq[91];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    seq[0] = 0;
    seq[1] = 1;
    for (int i = 2; i <= N; ++i) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }
    cout << seq[N];
}