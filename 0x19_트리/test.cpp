//
// Created by 서정윤 on 2024. 11. 1. 오후 6:24
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[501];
bool visited[501];
int N, M;

int count_tree(int edge) {
    visited[edge] = true;
    for (auto el : adj[edge]) {
        if (visited[el]) return 0;
        if (!count_tree(el)) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 0;
    while (true) {
        int cnt = 0;
        bzero(visited, sizeof(visited));
        cin >> N >> M;
        if (N + M == 0) break ;
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue ;
            cnt += count_tree(i);
        }
        cout << "Case " << ++c << ": ";
        if (cnt == 0) {
            cout << "No trees.\n";
        } else if (cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
        }
    }
}
