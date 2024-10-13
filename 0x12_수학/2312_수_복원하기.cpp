//
// Created by 서정윤 on 2024. 10. 13. 오후 7:07
//
#include <bits/stdc++.h>

using namespace std;
int N, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        for (int j = 2; j <= x; ++j) {
            int cnt = 0;
            while (x % j == 0) {
                cnt += 1;
                x /= j;
            }
            if (cnt > 0) {
                cout << j << " " << cnt << '\n';
            }
        }
    }
}