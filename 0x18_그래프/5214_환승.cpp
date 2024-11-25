//
// Created by 서정윤 on 2024. 11. 22. 오후 1:31
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[101001];
int visited[101001];
int N, K, M;
int mn = 0x7fffffff;

void BFS() {
    queue<int> Q;

    Q.push(1);
    visited[1] = 1;
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto edge : adj[cur]) {
            if (edge > N) { // hyper tube
                visited[edge] = visited[cur];
                Q.push(edge);
                continue ;
            }
            if (visited[edge]) continue ;
            visited[edge] = visited[cur] + 1;
            if (edge == N)
                return ;
            Q.push(edge);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> M;
    for (int i = 1; i <= M; ++i) {
        for (int j = 0; j < K; ++j) {
            int x;
            cin >> x;
            adj[x].push_back(i + N);
            adj[i + N].push_back(x);
        }
    }
    BFS();
    if (visited[N])
        cout << visited[N];
    else
        cout << -1;
}