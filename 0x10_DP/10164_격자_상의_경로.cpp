//
// Created by 서정윤 on 2025. 2. 1. 오전 9:44
//
#include <bits/stdc++.h>

using namespace std;
int N, M, K;
int DP[16][16];

int cal_dist(int start, int end) {
    int stx, sty;

    start -= 1;
    end -= 1;
    stx = start / M;
    sty = start % M;
    DP[stx][sty] = 1;
    for (int i = start; i <= end; ++i){
        int x = i / M;
        int y = i % M;
        if (x > stx)
            DP[x][y] += DP[x - 1][y];
        if (y > sty)
            DP[x][y] += DP[x][y - 1];
    }
    return DP[end / M][end % M];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    int ans = 0;
    if (!K) {
        ans = cal_dist(1, N * M);
    } else {
        ans = cal_dist(1, K);
        ans *= cal_dist(K, N * M);
    }
    cout << ans;

}