//
// Created by 서정윤 on 2024. 11. 4. 오후 8:32
//
#include <bits/stdc++.h>

using namespace std;
int K;
long long mn = numeric_limits<long long>::max(), mx;
bool ops[11]; // true -> '>'
bool visited[11];
char res[11];
char mx_c[11];
char mn_c[11];


void solve(int n, int pre) {
    if (n == K + 1) {
        long long val = atol(res);
        if (mn > val) {
            mn = val;
            memcpy(mn_c, res, sizeof(res));
        }
        if (mx < val) {
            mx = val;
            memcpy(mx_c, res, sizeof(res));
        }
        return ;
    }
    for (int i = 0; i <= 9; ++i) {
        if (visited[i]) continue ;
        if (n == 0 || (ops[n - 1] && pre > i) || (!ops[n - 1] && pre < i)) {
            visited[i] = true;
            res[n] = i + '0';
            solve(n + 1, i);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    for (int i = 0; i < K; ++i) {
        char x;
        cin >> x;
        if (x == '>')
            ops[i] = true;
    }
    solve(0, -1);
    cout << mx_c << '\n' << mn_c;
}