//
// Created by 서정윤 on 2024. 10. 2. 오후 4:15
//
#include <bits/stdc++.h>

using namespace std;
int T, N;
int days[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    /*
     * 1. 주식 하나를 산다.
     * 2. 원하는 만큼 가지고 있는 주식을 판다.
     * 3. 아무것도 안한다.
     * */
    while (T--) {
        cin >> N;

        for (int i = 0; i < N; ++i) {
            cin >> days[i];
        }
        long long val = 0;
        int mx = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (days[i] < mx) {
                val += mx - days[i];
            } else {
                mx = days[i];
            }
        }
        cout << val << '\n';
    }
}