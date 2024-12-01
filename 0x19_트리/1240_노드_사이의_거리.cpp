//
// Created by 서정윤 on 2024. 12. 1. 오후 7:54
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<pair<int, int> > adj[1001];

int find_dist(int st, int en, int par) {
    if (st == en)
        return 0;
    for (auto child : adj[st]) {
        if (child.first == par) continue ;
        if (child.first == en)
            return child.second;
        int res = find_dist(child.first, en, st);
        if (res != 0) {
            return res + child.second;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    int u, v, d;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        cout << find_dist(u, v, 0) << '\n';
    }
}
