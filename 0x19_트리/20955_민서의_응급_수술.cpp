//
// Created by 서정윤 on 2024. 12. 2. 오후 5:32
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100001];
int union_find[100001];
int N, M, detach_cnt;
bool visited[100001];

void DFS(int cur, int par) {
    for (auto child : adj[cur]) {
        if (child == par) continue ;
        if (visited[child]) {
            detach_cnt += 1;
            continue ;
        }
        visited[child] = 1;
        union_find[child] = union_find[cur];
        DFS(child, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; ++i) {
        union_find[i] = i;
    }
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue ;
        visited[i] = true;
        DFS(i, 0);
    }
    int connect_cnt = 0;
    memset(visited, 0, sizeof(visited));
    visited[union_find[1]] = true;

    for (int i = 2; i <= N; ++i) {
        if (!visited[union_find[i]]) {
            connect_cnt += 1;
            visited[union_find[i]] = true;
        }
    }
    cout << connect_cnt + detach_cnt / 2;
}