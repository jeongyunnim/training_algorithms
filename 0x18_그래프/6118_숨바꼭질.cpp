//
// Created by 서정윤 on 2024. 11. 11. 오후 4:57
//
#include <bits/stdc++.h>

using namespace std;
int N, M, mx, mx_i = 0x7fffffff, mx_c;
vector<int> adj[20001];
bool visited[20001];

void BFS(int s) {
    queue<pair<int, int> > Q;

    Q.push({s, 0});
    visited[s] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (mx < cur.second) {
            mx = cur.second;
            mx_c = 1;
            mx_i = cur.first;
        } else if (mx == cur.second) {
            mx_i = min(mx_i, cur.first);
            mx_c += 1;
        }
        for (auto node : adj[cur.first]) {
            if (visited[node]) continue ;
            visited[node] = true;
            Q.push({node, cur.second + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    BFS(1);
    cout << mx_i << " " << mx << " " << mx_c;
}