//
// Created by 서정윤 on 2024. 9. 23. 오후 11:42
//
#include <iostream>

using namespace std;
int tri[501][501];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j)
            cin >> tri[i][j];
    }
    if (N == 1) {
        cout << tri[0][0];
        return 0;
    }
    int mx = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j == 0)
                tri[i][j] += tri[i - 1][j];
            else if (j == i)
                tri[i][j] += tri[i - 1][j - 1];
            else
                tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
            if (i == N - 1) {
                mx = max(tri[i][j], mx);
            }
        }
    }
    cout << mx;
}