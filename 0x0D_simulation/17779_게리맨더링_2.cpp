//
// Created by 서정윤 on 2024. 12. 18. 오후 4:08
//
#include <bits/stdc++.h>

using namespace std;
int N;
int board[21][21];
int mn = 0x7fffffff;

void cal_gap(int x, int y, int d1, int d2) {
    int total[6];

    int check[21][21];
    memset(check, 0, sizeof(check));
    memset(total, 0, sizeof(total));
    for (int i = 1; i < x + d1; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (i - x == y - j) break ;
            int population = board[i][j];
            check[i][j] = 1;
            total[1] += population;
        }
    }
    for (int i = 1; i <= x + d2; ++i) {
        for (int j = N; j > y; --j) {
            if (i - x == j - y) break ;
            int population = board[i][j];
            check[i][j] = 2;
            total[2] += population;
        }
    }
    for (int i = x + d1; i <= N; ++i) {
        for (int j = 1; j < y - d1 + d2; ++j) {
            if (i - x - d1 == j - y + d1) break ;
            int population = board[i][j];
            check[i][j] = 3;
            total[3] += population;
        }
    }
    for (int i = x + d2 + 1; i <= N; ++i) {
        for (int j = N; j >= y - d1 + d2; --j) {
            if (i - x - d2 == y + d2 - j) break ;
            int population = board[i][j];
            check[i][j] = 4;
            total[4] += population;
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (check[i][j] != 0) continue ;
            int population = board[i][j];
            check[i][j] = 5;
            total[5] += population;
        }
    }
//    cout << "[check]\n";
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= N; ++j) {
//            cout << check[i][j] << " ";
//        }
//        cout << '\n';
//    }
    if (!total[1] || !total[2] || !total[3] || !total[4] || !total[5])
        return ;
    int cur_mx = max({total[1], total[2], total[3], total[4], total[5]});
    int cur_mn = min({total[1], total[2], total[3], total[4], total[5]});
    mn = min(mn, cur_mx - cur_mn);
}

void check_min(int x, int y) {
    for (int d1 = 1; d1 <= N; ++d1) {
        for (int d2 = 1; d2 <= N; ++d2) {
            if (x + d1 + d2 > N || y - d1 < 0 || y + d2 > N) continue ; // x - d1 < 0 이라는 조건은 없었다.
            cal_gap(x, y, d1, d2);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            check_min(x, y);
        }
    }
    cout << mn;
}

/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
 */