//
// Created by 서정윤 on 2024. 10. 7. 오후 4:19
//
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    vector<bool> state(N + 1, true);
    state[0] = false;
    state[1] = false;
    int count = 0;
    for (int i = 2; i <= N; ++i) {
        if (!state[i]) continue ;
        if (++count == M) {
            cout << i;
            return (0);
        }
        for (int j = i * i; j <= N; j += i) {
            if (!state[j]) continue ;
            state[j] = false;
            if (++count == M) {
                cout << j;
                return (0);
            }
        }
    }

}