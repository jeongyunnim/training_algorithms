//
// Created by 서정윤 on 2024. 11. 11. 오후 5:16
//
#include <bits/stdc++.h>

using namespace std;
int T, N, M;
vector<int> adj[20001];
int visited[20001];

bool BFS(int num) {
    queue<pair<int, int> > Q;
    Q.push({num, 1});
    visited[num] = true;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto node : adj[cur.first]) {
            if (visited[node]) {
                if (visited[node] == cur.second)
                    return false;
                else continue ;
            } else {
                visited[node] = cur.second % 2 + 1;
                Q.push({node, cur.second % 2 + 1});
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        //BFS 탐색
        int is_bipartite = true;
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue ;
            if (!BFS(i)) {
                is_bipartite = false;
                break;
            }
        }
        if (is_bipartite) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        for (int i = 1; i <= N; ++i) {
            adj[i].clear();
        }
        bzero(visited, sizeof(visited));
    }
}