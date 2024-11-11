//
// Created by 서정윤 on 2024. 11. 11. 오후 3:04
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int N, M;
int bit_limit = 1;
int visited[1000001];
queue<pair<int, int> > Q;

void print_bit(int n) {
    int cur = 19;

    cout << n << ": ";
    while (cur >= 0) {
        if (n & (1 << cur)) {
            cout << 1;
        } else {
            cout << 0;
        }
        if (cur % 4 == 0) cout << ' ';
        n &= ~(1 << cur);
        --cur;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    while (1 << bit_limit < N) {
        bit_limit += 1;
    }
    int x;
    for (int i = 0; i < M; ++i) {
        cin >> x;
        visited[x] = true;
        Q.push({x, 0});
    }
    int mx = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        mx = max(mx, cur.Y);
        for (int i = 0; i < bit_limit; ++i) { // 000: 001 010 100
            int nx = cur.X ^ (1 << i);
            if (nx > N || visited[nx]) continue ;
            visited[nx] = true;
            Q.push({nx, cur.Y + 1});
        }
    }
    cout << mx;
}