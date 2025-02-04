//
// Created by 서정윤 on 2025. 2. 4. 오후 8:13
//
#include <bits/stdc++.h>

using namespace std;
int area[101];
int floyd[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;
    for (int i = 1; i <= N; ++i) {
        cin >> area[i];
    }

    for (int i = 1; i <= N; ++i) {
        fill(floyd[i], floyd[i] + 101, 0x7fffffff / 2);
        floyd[i][i] = 0;
    }

    for (int i = 0; i < R; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        if (floyd[u][v] > len) {
            floyd[u][v] = len;
            floyd[v][u] = len;
        }
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; ++j) {
                if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                    floyd[j][i] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= N; ++i) {
        int cur = 0;
        for (int j = 1; j <= N; ++j) {
            if (floyd[i][j] <= M)
                cur += area[j];
        }
        if (mx < cur)
            mx = cur;
    }
    cout << mx;
}