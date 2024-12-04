//
// Created by 서정윤 on 2024. 12. 4. 오후 3:48
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[32001];
int indegrees[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegrees[v] += 1;
    }
    set<int> S;
    for (int i = 1; i <= N; ++i) {
        if (indegrees[i] == 0) {
            S.insert(i);
        }
    }
    while (!S.empty()) {
        auto cur = S.begin();
        cout << *cur << ' ';
        for (auto outdegree : adj[*cur]) {
            indegrees[outdegree] -= 1;
            if (indegrees[outdegree] == 0)
                S.insert(outdegree);
        }
        S.erase(cur);
    }
}