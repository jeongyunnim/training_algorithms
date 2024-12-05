//
// Created by 서정윤 on 2024. 12. 5. 오후 3:29
//
#include <bits/stdc++.h>

using namespace std;
int V, E;
vector<int> p(10001, -1);
tuple<int, int, int> edge[100001];

int find(int u) {
    if (p[u] == -1) return u;
    else return p[u] = find(p[u]);
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

    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int v, e, cost;
        cin >> v >> e >> cost;
        edge[i] = {cost, v, e};
    }
    sort(edge, edge + E);
    int cnt = 0, ans = 0;
    for (int i = 0; i < E; ++i) {
        int v, e, cost;
        tie(cost, v, e) = edge[i];
        if (!uni(v, e)) continue ;
        ans += cost;
        cnt += 1;
        if (cnt == V - 1)
            break ;
    }
    cout << ans;
}