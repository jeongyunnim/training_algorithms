//
// Created by 서정윤 on 2024. 11. 10. 오후 4:18
//
#include <bits/stdc++.h>

using namespace std;
int N, M, mn = 0x7fffffff;
vector<int> adj[101];
bool visited[101];

int BFS(int num) {
    queue<pair<int, int> > Q;
    int point = 0;

    bzero(visited, sizeof(visited));
    visited[num] = 1;
    Q.push({num, 0});
    while (!Q.empty()) {
        auto cur = Q.front();
        point += cur.second;
        Q.pop();
        for (auto node : adj[cur.first]) {
            if (visited[node]) continue ;
            visited[node] = 1;
            Q.push({node, cur.second + 1});
        }
    }
    return point;
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
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        int point = BFS(i);

        if (point < mn) {
            res = i;
            mn = point;
        }
    }
    cout << res;
}