//
// Created by 서정윤 on 2024. 10. 18. 오후 4:09
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
vector<bool> visited(1001);
int N, M, x, y, cnt;

void DFS() {
    stack<int> S;
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue ;
        S.push(i);
        cnt += 1;
        while (!S.empty()) {
            int cur = S.top();
            S.pop();
            if (visited[cur]) continue ;
            visited[cur] = true;
            for (auto next : adj[cur]) {
                if (visited[next]) continue ;
                S.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS();
    cout << cnt;
}