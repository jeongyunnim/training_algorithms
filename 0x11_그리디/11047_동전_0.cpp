//
// Created by 서정윤 on 2024. 9. 29. 오후 5:12
//
#include <bits/stdc++.h>

using namespace std;
int coins[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, sum;

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }
    sum = K;
    int offset = N - 1, cnt = 0, temp;
    while (sum) {
        if (sum >= coins[offset]) {
            temp = sum / coins[offset];
            cnt += temp;
            sum -= temp * coins[offset];
        }
        offset -= 1;
    }
    cout << cnt;
}