//
// Created by 서정윤 on 2024. 12. 24. 오후 7:39
//
#include <bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCD(long long a, long long b) {
    return a * b / GCD(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b;
        if (a < b)
            swap(a, b);
        cout << LCD(a, b) << '\n';
    }
}