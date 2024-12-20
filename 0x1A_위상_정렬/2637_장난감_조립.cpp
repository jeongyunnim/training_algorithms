//
// Created by 서정윤 on 2024. 12. 20. 오후 2:31
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adj[101];
int indegrees[101];
int required[101][101];
int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v, cnt;
        cin >> u >> v >> cnt;
        adj[v].push_back({u, cnt});
        indegrees[u] += 1;
    }
    queue<pair<int, bool> > Q;
    for (int i = 1; i <= N; ++i) {
        if (indegrees[i] == 0) {
            Q.push({i, 0});
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto outdegree : adj[cur.first]) {
            indegrees[outdegree.first] -= 1;
            if (cur.second == 0) {
                required[outdegree.first][cur.first] += outdegree.second;
            } else {
                for (int i = 1; i < N; ++i) {
                    required[outdegree.first][i] += required[cur.first][i] * outdegree.second;
                }
            }
            if (indegrees[outdegree.first] == 0) {
                Q.push({outdegree.first, 1});
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (required[N][i]) {
            cout << i << " " << required[N][i] << '\n';
        }
    }
}