
//
// Created by 서정윤 on 2024. 11. 1. 오후 6:24
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[501];
bool visited[501];
int N, M;

bool is_tree(int vertex, int parent) {
    if (visited[vertex]) return false ;
    visited[vertex] = true;
    for (auto node : adj[vertex]) {
        if (node == parent) continue ;
        if (visited[node]) return false;
        if (!is_tree(node, vertex)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c = 0;
    int cnt;
    while (true) {

        cin >> N >> M;
        bzero(visited, sizeof(visited));
        for (int i = 1; i <= N; ++i) { // 초기화 조건을 잘못 설정... 6회 시도
            adj[i].clear();
        }
        cnt = 0;
        if (N + M == 0) break ;
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue ;
            if (is_tree(i, 0))
                cnt += 1;
        }
        cout << "Case " << ++c << ": ";
        if (cnt == 0) {
            cout << "No trees.\n";
        } else if (cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }
    }
}
