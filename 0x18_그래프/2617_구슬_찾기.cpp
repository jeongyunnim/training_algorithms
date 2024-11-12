//
// Created by 서정윤 on 2024. 11. 11. 오후 11:11
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj_heavy[100];
vector<int> adj_light[100];
bool visited[100];

int DFS_heavy(int num) {
    int cnt = 1;
    visited[num] = true;
    for (auto node : adj_heavy[num]) {
        if (visited[node]) continue ;
        cnt += DFS_heavy(node);
    }
    return cnt;
}

int DFS_light(int num) {
    int cnt = 1;
    visited[num] = true;
    for (auto node : adj_light[num]) {
        if (visited[node]) continue ;
        cnt += DFS_light(node);
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
        adj_heavy[y].push_back(x);
        adj_light[x].push_back(y);
    }
    int cnt = N;
    for (int i = 1; i <= N; ++i) {
        bzero(visited, sizeof(visited));
        if (DFS_heavy(i) - 1 > N / 2)
            continue ;
        bzero(visited, sizeof(visited));
        if (DFS_light(i) - 1 > N / 2)
            continue ;
        cnt -= 1;
    }
    cout << cnt;
}