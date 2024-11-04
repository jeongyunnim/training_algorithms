//
// Created by 서정윤 on 2024. 11. 4. 오후 6:37
//
#include <bits/stdc++.h>

using namespace std;
int N, mn = 0x7fffffff;
int board[11][11];
int order[11];
bool visited[11];

int cal() {
    int res = 0;
    for (int i = 0; i < N - 1; ++i) {
        int cur = order[i];
        int next = order[i + 1];
        res += board[cur][next];
    }
    res += board[order[N - 1]][order[0]];
    return res;
}

void solve(int n) {
    if (n == N) {
        if (board[order[N - 1]][order[0]] != 0) {
            mn = min(mn, cal());
        }
        return ;
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue ;
        // choose destination - check the connection that previous village to current village.
        if (n != 0 && board[order[n - 1]][i] == 0) continue ;
        visited[i] = true;
        order[n] = i;
        solve(n + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
    }

    solve(0);
    cout << mn;
}