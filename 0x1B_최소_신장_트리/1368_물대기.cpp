//
// Created by 서정윤 on 2024. 12. 5. 오후 5:39
//
#include <bits/stdc++.h>

using namespace std;
int costs[301][301];
vector<int> p(301, -1);
tuple<int, int, int> edges[301 * 301 / 2];

int find(int x) {
    if (p[x] == -1) return x;
    else return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    else if (u > v)
        swap(u, v);
    p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x;
    cin >> N;
    int edges_idx = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        edges[edges_idx++] = {x, 0, i};
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> x;
            if (j > i) {
                edges[edges_idx++] = {x, i, j};
            }
        }
    }
    sort(edges, edges + edges_idx);
    int cnt = 0, ans = 0;
    for (int i = 0; i < edges_idx; ++i) {
        int cost, u, v;
        tie(cost, u, v) = edges[i];
        if (!uni(u, v)) continue ;
        ans += cost;
        cnt += 1;
        if (cnt == N)
            break ;
    }
    cout << ans;
}