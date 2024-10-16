//
// Created by 서정윤 on 2024. 10. 15. 오후 9:07
//
#include <bits/stdc++.h>

using namespace std;
int K, N;
int input[10001];

bool solve(long long x) {
    long long cur = 0;
    for (int i = 0; i < K; ++i) {
        cur += input[i] / x;
    }
    return cur >= N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> input[i];
    }
    long long l = 1;
    long long r = 0x7fffffffl + 1; // 도저히 모르겠어. 왜?
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
}