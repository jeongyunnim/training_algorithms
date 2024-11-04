//
// Created by 서정윤 on 2024. 11. 4. 오후 5:56
//
#include <bits/stdc++.h>

using namespace std;
int N;
int arr[9];
int comb[9];
bool visited[9];
int mx = numeric_limits<int>::min();

int cal() {
    int res = 0;
    for (int i = 0; i < N - 1; ++i) {
        res += abs(comb[i] - comb[i + 1]);
    }
    return res;
}

void solve(int n) {
    if (n == N) {
        mx = max(mx, cal());
        return ;
    }
    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue ;
        visited[i] = true;
        comb[n] = arr[i];
        solve(n + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    solve(0);
    cout << mx;
}