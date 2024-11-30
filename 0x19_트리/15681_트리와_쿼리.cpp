//
// Created by 서정윤 on 2024. 11. 30. 오후 3:43
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100001];
int N, R, Q, cnt[100001];

int DFS(int cur, int par) {
    int subtrees = 1;
    for (auto edge : adj[cur]) {
        // tree 형태기 때문에 부모만 체크하면 된다.
        if (edge == par) continue ;
        subtrees += DFS(edge, cur);
    }
    cnt[cur] = subtrees;
    return subtrees;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(R, -1);
    for (int i = 0; i < Q; ++i) {
        int u;
        cin >> u;
        cout << cnt[u] << '\n';
    }
}