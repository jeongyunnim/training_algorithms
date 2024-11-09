//
// Created by 서정윤 on 2024. 11. 8. 오후 5:33
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adjacent[501];
int cnt;
bool visited[501];

void DFS(int cur) {

    if (!visited[cur])
        cnt += 1;
    visited[cur] = true;
    for (auto node : adjacent[cur]) {
        if (visited[node]) continue ;
        visited[node] = true;
        cnt += 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        adjacent[x].push_back(y);
        adjacent[y].push_back(x);
    }
    visited[1] = 1;
    for (auto node : adjacent[1]) {
        DFS(node);
    }
    cout << cnt;
}