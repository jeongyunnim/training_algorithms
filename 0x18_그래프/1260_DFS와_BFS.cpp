//
// Created by 서정윤 on 2024. 10. 18. 오후 4:25
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
bool visited[1001];
int N, M, V, x, y;

void BFS() {
    queue<int> Q;
    Q.push(V);
    visited[V] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        cout << cur << " ";
        Q.pop();
        sort(adj[cur].begin(), adj[cur].end());
        for (auto next : adj[cur]) {
            if (visited[next]) continue ;
            visited[next] = true;
            Q.push(next);
        }
    }
    cout << '\n';
}

void DFS() {
    stack<int> S;
    S.push(V);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        if (visited[cur]) continue ;
        visited[cur] = true;
        cout << cur << " ";
        sort(adj[cur].begin(), adj[cur].end(), greater<int>());
        for (auto next : adj[cur]) {
            if (visited[next]) continue ;
            S.push(next);
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS();
    bzero(visited, sizeof(visited));
    BFS();
}