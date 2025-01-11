//
// Created by 서정윤 on 2025. 1. 9. 오후 3:10
//
#include <bits/stdc++.h>

using namespace std;
int N, M, K;
vector<tuple<int, int, int> > V;
int p[1001];
int cables[100001];

int find(int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;
    if (u > v)
        swap(u, v);
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    memset(p, -1, sizeof(p));
    // 가상의 노드 0을 두고 0과 모두 연결되도록 처리
    for (int i = 0; i < K; ++i) {//임의로 0을 연결해놓고 시작하는 대신, 비용이 0인 간선을 추가
        int x;
        cin >> x;
        V.push_back({0, 0, x});
    }
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        V.push_back({w, u, v});
    }
    sort(V.begin(), V.end());
    int sum = 0, cnt = 0;
    for (int i = 0; i < M + K - 1; ++i) {
        int u, v, w;
        tie(w, u, v) = V[i];
        if (!uni(u, v)) continue ;
        sum += w;
        ++cnt;
        if (cnt == N) break ;
    }
    cout << sum;
}