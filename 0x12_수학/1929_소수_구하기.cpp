//
// Created by 서정윤 on 2024. 10. 5. 오후 9:32
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<bool> state(M + 1, true);
    state[1] = false;
    for (int i = 2; i <= M / i; ++i) {
        if (!state[i]) continue ;
        for (int j = i * i; j <= M; j += i) {
            state[j] = false;
        }
    }
    for (int i = N; i <= M; ++i) {
        if (state[i]) {
            cout << i << '\n';
        }
    }

}