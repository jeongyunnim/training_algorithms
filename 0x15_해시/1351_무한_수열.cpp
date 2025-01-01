//
// Created by 서정윤 on 2025. 1. 1. 오후 2:36
//
#include <bits/stdc++.h>

using namespace std;
unordered_map<long long, long long> M;
long long N, P, Q;

long long solve(long long n) {
    if (M[n] != 0)
        return M[n];
    M[n] = solve(n / P) + solve(n / Q);
//    cout << n << " " << M[n] << '\n';
    return M[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;
    M[0] = 1;
    M[1] = 2;
    cout << solve(N);
}