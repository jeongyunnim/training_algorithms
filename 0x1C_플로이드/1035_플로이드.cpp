//
// Created by 서정윤 on 2025. 1. 20. 오후 12:25
//
#include <bits/stdc++.h>

using namespace std;
int city[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N; ++i)
        fill(city[i] + 1, city[i] + N + 1, 0x7fffffff / 2);
    for (int i = 1; i <= N; ++i) {
        city[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (city[a][b] > c)
            city[a][b] = c;
    }

    //floyd
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (city[i][j] > city[i][k] + city[k][j])
                    city[i][j] = city[i][k] + city[k][j];
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (city[i][j] == 0x7fffffff / 2)
                cout << "0 ";
            else
                cout << city[i][j] << ' ';
        }
        cout << '\n';
    }
}