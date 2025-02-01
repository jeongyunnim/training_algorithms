//
// Created by 서정윤 on 2025. 1. 25. 오전 9:29
//
#include <bits/stdc++.h>

using namespace std;
int DP[30][2]; // [30일] = {첫쨋날의 계수, 둘쨋날의 계수}

int main() {
    int d, k, fir, sec;

    cin >> d >> k;

    DP[1][0] = DP[1][1] = DP[2][0] = 1;
    DP[2][1] = 2;
    d -= 2; // 1번째 날, 2번째 날
    for (int i = 3; i <= d; ++i) {
        DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
        DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
    }
    fir = 1;
    while (1) {
        if ((k - fir * DP[d][0]) % DP[d][1] == 0) {
            sec = (k - fir * DP[d][0]) / DP[d][1];
            break ;
        }
        fir += 1;
    }
    cout << fir << '\n' << sec;
}