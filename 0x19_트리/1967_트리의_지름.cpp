//
// Created by 서정윤 on 2024. 12. 14. 오후 3:01
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adj[10001];
int mx;

int DFS(int cur, int par) {
    priority_queue<int, vector<int>, greater<int> > dists;
    int ret = 0;

    for (auto child : adj[cur]) {
        if (child.first == par) continue ;
        dists.push(DFS(child.first, cur) + child.second);
        if (dists.size() == 3) {
            dists.pop();
        }
    }
    if (dists.empty())
        return 0;
    if (dists.size() == 1) {
        mx = max(mx, dists.top());
    } else {
        int secondary = dists.top();
        dists.pop();
        mx = max(mx, secondary + dists.top());
    }
    ret = dists.top();
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[v].push_back({u, cost});
        adj[u].push_back({v, cost});
    }

    DFS(1, -1);
    cout << mx;
}