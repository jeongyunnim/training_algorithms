//
// Created by 서정윤 on 2024. 9. 30. 오후 2:22
//
#include <bits/stdc++.h>

using namespace std;

int N;
int rope[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> rope[i];
    }
    int mx = 0;
    sort(rope, rope + N);
    for (int i = 0; i < N; ++i) {
        if (mx < rope[i] * (N - i))
            mx = rope[i] * (N - i);
    }
    cout << mx;
}