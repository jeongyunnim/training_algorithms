//
// Created by 서정윤 on 2024. 11. 4. 오후 6:26
//
#include <bits/stdc++.h>

using namespace std;
int N;
char comb[17];
bool visited[9];

void solve(int n) {
    if (n == N) {
        cout << comb << '\n';
        return ;
    }

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue ;
        visited[i] = true;
        comb[2 * n] = i + '0';
        comb[2 * n + 1] = ' ';
        solve(n + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> N;
    solve(0);
}