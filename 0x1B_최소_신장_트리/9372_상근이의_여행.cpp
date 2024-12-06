//
// Created by 서정윤 on 2024. 12. 6. 오전 12:36
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
        }
        cout << N - 1 << '\n'; // 간선의 가중치가 1과 같다면 최소 비용은 언제나 "노드 수 - 1"이다.
    }
}