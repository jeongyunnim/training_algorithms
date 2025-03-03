//
// Created by 서정윤 on 2025. 3. 3. 오후 10:48
//
#include <bits/stdc++.h>

using namespace std;
int cities[20][20];
int visited[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, sum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cities[i][j];
            if (i < j)
                sum += cities[i][j];
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i > j || i == k || j == k) continue ;
                if (cities[i][j] == cities[i][k] + cities[k][j]) {
                    if (visited[i][j]) continue ;
                    sum -= cities[i][j];
                    visited[i][j] = 1;
                } else if (cities[i][j] > cities[i][k] + cities[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << sum;
}