//
// Created by 서정윤 on 2024. 9. 24. 오후 2:06
//
#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    long long cnt[91];
    cnt[1] = 1;
    cnt[2] = 1;
    for (int i = 3; i <= N; ++i) {
        cnt[i] = cnt[i - 1] + cnt[i - 2];
    }
    cout << cnt[N];
}