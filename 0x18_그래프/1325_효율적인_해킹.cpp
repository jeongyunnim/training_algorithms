//
// Created by 서정윤 on 2024. 11. 10. 오후 4:31
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10001];
bool visited[10001];
int N, M;

int DFS(int num) {
    int cnt = 1;

    visited[num] = true;
    for (auto node : adj[num]) {
        if (visited[node]) continue ;
        visited[node] = true;
        cnt += DFS(node);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }
    int mx = -1; // 초기화를 잊지말자.
    vector<int> res;
    for (int i = 1; i <= N; ++i) {
        bzero(visited, sizeof(visited));

        int cnt = DFS(i);
        if (cnt > mx) {
            res.clear();
            res.push_back(i);
            mx = cnt;
        } else if (cnt == mx) {
            res.push_back(i);
        }
    }
    for (int node : res) {
        cout << node << " ";
    }
}