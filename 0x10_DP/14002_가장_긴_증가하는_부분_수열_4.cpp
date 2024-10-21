//
// Created by 서정윤 on 2024. 10. 18. 오후 8:10
//
#include <bits/stdc++.h>

using namespace std;
int N, sz;
int input[1001];
int dp[1001];
int trace[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    int mx = 0, mxi;
    vector<int> V;
    dp[0] = 0;
    memset(trace, 0xff, sizeof(trace));
    for (int i = 0; i < N; ++i) {
        int longest = 0, li = -1;
        for (int j = 0; j < i; ++j) {
            if (input[j] < input[i] && longest < dp[j]) {
                longest = dp[j]; // 가장 긴 항목 탐색
                li = j; // 해당 값 저장
            }
        }
        dp[i] = longest + 1;
        trace[i] = li;
        if (mx < dp[i]) {
            mx = dp[i];
            mxi = i;
        }
    }
    cout << mx << '\n';

    int next = mxi;
    while (next >= 0) {
        V.push_back(input[next]);
        next = trace[next];
    }
    for (auto it = V.rbegin(); it != V.rend(); it++) {
        cout << *it << " ";
    }
}