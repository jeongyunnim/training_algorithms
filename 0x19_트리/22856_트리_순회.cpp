//
// Created by 서정윤 on 2024. 12. 1. 오후 10:58
//
#include <bits/stdc++.h>

using namespace std;
int N, cnt;
int adj[100001][2];
bool visited[100001];

void add_cnt() {
    if (N == 0)
        return ;
    cnt += 1;
}

void DFS(int cur) {
    int l = adj[cur][0], r = adj[cur][1];
    if (l != -1) {
        add_cnt();
        DFS(adj[cur][0]);
        add_cnt();
    }
    if (!visited[cur]) {
        visited[cur] = true;
        N -= 1;
    }
    if (r != -1) {
        add_cnt();
        DFS(adj[cur][1]);
        add_cnt();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int r, a, b;
        cin >> r >> a >> b;
        adj[r][0] = a;
        adj[r][1] = b;
    }
    DFS(1);
    cout << cnt;
}