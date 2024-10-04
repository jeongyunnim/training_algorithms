//
// Created by 서정윤 on 2024. 10. 4. 오후 7:27
//
#include <bits/stdc++.h>

using namespace std;
long long input[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input+N);

    for (int i = 0; i < M; ++i) {
        input[0] = input[0] + input[1];
        input[1] = input[0];
        sort(input, input+N);
    }
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        res += input[i];
    }
    cout << res;
}