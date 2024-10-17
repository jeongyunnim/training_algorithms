//
// Created by 서정윤 on 2024. 10. 16. 오후 10:56
//
#include <bits/stdc++.h>

using namespace std;
int N, S;
int a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int ans = 0x7fffffff, sum = a[0], en = 0;
    for (int st = 0; st < N; ++st) {
        while (en < N && sum < S) {
            en += 1;
            sum += a[en];
        }
        if (en == N) break ;
        sum -= a[st];
        ans = min(ans, en - st + 1);
    }
    if (ans != 0x7fffffff)
        cout << ans;
    else
        cout << 0;
}