//
// Created by 서정윤 on 2024. 10. 25. 오후 2:51
//
#include <bits/stdc++.h>

using namespace std;
int digits[10];

int main() {
    int N;

    cin >> N;
    for (int i = 0; i < 10; ++i) {
        digits[i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 8; j >= 0; --j) {
            digits[j] += digits[j + 1];
            digits[j] %= 10007;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += digits[i];
        sum %= 10007;
    }
    cout << sum << '\n';
}