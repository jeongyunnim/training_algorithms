//
// Created by 서정윤 on 2024. 10. 8. 오후 2:48
//
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    int input[101];
    cin >> T;
    while (T--) {
        cin >> N;
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> input[i];
        }
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                sum += gcd(input[i], input[j]);
            }
        }
        cout << sum << '\n';
    }
}