//
// Created by 서정윤 on 2024. 11. 21. 오후 2:37
//
#include <bits/stdc++.h>
#define MAX_VAL 10001

using namespace std;
int N, K;
set<int> coins;
int dp[MAX_VAL];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        coins.insert(x);
    }
    for (int i = 1; i <= K; ++i) {
        dp[i] = MAX_VAL;
        for (auto coin : coins) {
            if (i < coin) break ;
            dp[i] = min({dp[i], dp[i - coin]}); // 여기에 +1 을 해주면 다음 비교에 +1이 반영된 값과 비교하게 된다.
        }
//        cout << i << ": " << dp[i] << '\n';
        dp[i] += 1; // INT_MAX인 경우 OVERFLOW 문제 발생
    }
    if (dp[K] < MAX_VAL)
        cout << dp[K];
    else
        cout << -1;
}