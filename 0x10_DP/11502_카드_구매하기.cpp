//
// Created by 서정윤 on 2024. 10. 24. 오후 2:30
//
#include <bits/stdc++.h>

using namespace std;
int N;
int packs[1001];
int T[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> packs[i];
    }
    T[1] = packs[1];

    for (int i = 2; i <= N; ++i) {
        int max_val = packs[i];
        for (int j = i - 1; j >= i/2; --j) {
            max_val = max(max_val, T[j] + T[i - j]);
        }
        T[i] = max_val;
    }
    cout << T[N];
}