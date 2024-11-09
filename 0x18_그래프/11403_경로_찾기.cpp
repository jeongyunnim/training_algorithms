//
// Created by 서정윤 on 2024. 11. 9. 오후 5:23
//
#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> adj[101];
bool visited[101];

void DFS(int cur) {
    for (auto node : adj[cur]) {
        if (visited[node]) continue ;
//        cout << cur << "] -> " << node << '\n';
        visited[node] = 1;
        DFS(node);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            bool is_connected;
            cin >> is_connected;
            if (is_connected)
                adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= N; ++i) {
        bzero(visited, sizeof(visited));
        DFS(i);
        for (int j = 1; j <= N; ++j) {
            cout << visited[j];
            if (j == N) cout << '\n';
            else cout << " ";
        }
    }
}