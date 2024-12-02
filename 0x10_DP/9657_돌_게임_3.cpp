//
// Created by 서정윤 on 2024. 12. 2. 오후 6:42
//
#include <bits/stdc++.h>

using namespace std;
bool dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    dp[1] = 1;
    dp[3] = 1;
    dp[4] = 1;
    for (int i = 5; i <= N; ++i) {
        if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }
    if (dp[N])
        cout << "SK";
    else
        cout << "CY";
}