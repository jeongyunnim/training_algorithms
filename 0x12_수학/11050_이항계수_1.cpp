//
// Created by 서정윤 on 2024. 10. 7. 오후 3:20
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    long long ans = 1;
    for (int i = 0; i < M; ++i) {
        ans *= N--;
        ans %= 10007;
    }
    for (int i = M; i > 1; --i) {
        ans /= i;
    }
    cout << ans;
}