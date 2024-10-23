//
// Created by 서정윤 on 2024. 10. 23. 오후 4:25
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int comb[41];

    cin >> N >> M;
    comb[1] = 1;
    comb[2] = 2;
    for (int i = 3; i < 41; ++i) {
        comb[i] = comb[i - 1] + comb[i - 2];
    }
    int start = 1;
    int x;
    int cnt = 1;
    for (int i = 0; i < M; ++i) {
        cin >> x;
        if (x - start > 0)
            cnt *= comb[x - start];
        start = x + 1;
    }
    if (N - start + 1 > 0)
        cnt *= comb[N - start + 1];
    cout << cnt;
}