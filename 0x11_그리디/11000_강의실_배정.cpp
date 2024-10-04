//
// Created by 서정윤 on 2024. 10. 4. 오후 6:55
//
#include <bits/stdc++.h>

using namespace std;
int s[200001];
int e[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i] >> e[i];
    }
    sort(s, s + N);
    sort(e, e + N);
    int cnt = 0, mx = 0, e_offset = 0;
    for (int i = 0; i < N; ++i) {
        cnt += 1;
        while (e_offset < N && e[e_offset] <= s[i]) {
            e_offset += 1;
            cnt -= 1;
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}