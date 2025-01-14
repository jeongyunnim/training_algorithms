//
// Created by 서정윤 on 2025. 1. 14. 오전 10:02
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt = 31;
    cin >> N;
    for (int i = 0; i < 32; ++i) {
        if (N & (1 << i)) break ;
        cnt -= 1;
    }
    cout << cnt;
}