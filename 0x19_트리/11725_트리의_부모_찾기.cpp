//
// Created by 서정윤 on 2024. 10. 18. 오후 5:02
//
#include <bits/stdc++.h>

using namespace std;
int N, x, y;
vector<int> adj[100001];
int parent[100001];

void DFS(int edge, int p) {
    parent[edge] = p;
    for (auto next : adj[edge]) {
        if (parent[edge] == next) continue ;
        DFS(next, edge);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    DFS(1, 0);
    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }
}