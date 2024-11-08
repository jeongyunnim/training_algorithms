//
// Created by 서정윤 on 2024. 11. 8. 오후 5:33
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adjacent[101];
int cnt;
bool visited[101];

int DFS(int cur) {

    if (visited[cur]) return 0;
    visited[cur] = true;
    cnt += 1;
    for (auto node : adjacent[cur]) {
        if (visited[node]) continue ;
        DFS(node);
    }
    return cnt;
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
    DFS(1);
    cout << cnt - 1;
}