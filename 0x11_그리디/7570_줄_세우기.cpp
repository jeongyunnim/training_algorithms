//
// Created by 서정윤 on 2024. 11. 25. 오후 10:05
//
#include <bits/stdc++.h>

using namespace std;
int visited[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, mx = 0 ,x;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (visited[x - 1]) {
            visited[x] = visited[x - 1] + 1;
        } else {
            visited[x] = 1;
        }
        mx = max(mx, visited[x]);
    }
//    for (int i = 0; i < N; ++i) {
//        cout << dp[i] << ' ';
//    }
    cout << N - mx;
}