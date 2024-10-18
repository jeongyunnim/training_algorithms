//
// Created by 서정윤 on 2024. 10. 18. 오후 6:31
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[32001];
vector<int> ans;
int N, M, x, y;
int indegree[32001];

void solve() {
    queue<int> Q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        ans.push_back(cur);
        for (int next : adj[cur]) {
            indegree[next] -= 1;
            if (indegree[next] == 0) {
                Q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        indegree[y] += 1;
    }
    solve();
    for (auto el : ans) {
        cout << el << " ";
    }
}