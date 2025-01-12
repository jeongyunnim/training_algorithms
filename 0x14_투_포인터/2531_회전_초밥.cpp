//
// Created by 서정윤 on 2025. 1. 12. 오전 10:49
//
#include <bits/stdc++.h>

using namespace std;
int sushi[3000001];
int comb[3001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
    }
    int s, e, cnt = 0, mx = 0;
    for (e = 0; e < k; ++e) {
        int cur = sushi[e];
        if (comb[cur] == 0) {
            cnt += 1;
        }
        comb[cur] += 1;
    }
    mx = cnt;
    for (s = 0; s < N; ++s) {
        int pre = sushi[s], cur = sushi[e];
        comb[pre] -= 1;
        if (comb[pre] == 0) {
            cnt -= 1;
        }
        if (comb[cur] == 0) {
            cnt += 1;
        }
        comb[cur] += 1;
        ++e;
        if (e == N) {
            e = 0;
        }
        if (!comb[c])
            mx = max(mx, cnt + 1);
        else
            mx = max(mx, cnt);
    }
    cout << mx;
}