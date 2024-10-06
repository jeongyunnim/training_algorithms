//
// Created by 서정윤 on 2024. 10. 6. 오후 3:41
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M, x, y;
    bool is_find;
    cin >> T;
    while (T--) {
        cin >> N >> M >> x >> y;
        is_find = false;
//        if (x == 1 && y == 1) {
//            cout << 1 << '\n';
//            continue ;
//        }
        for (int i = x; i <= M * N; i += N) {
            if (i % M == y % M) {
                cout << i << '\n';
                is_find = true;
                break ;
            }
        }
        if (!is_find)
            cout << -1 << '\n';
    }
}