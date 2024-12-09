//
// Created by 서정윤 on 2024. 12. 9. 오후 4:25
//
#include <bits/stdc++.h>

using namespace std;
int p[100001];
tuple<int, int, int> village[1000001];

int find(int t) {
    if (p[t] == -1) return t;
    else return p[t] = find(p[t]);
}

int uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (u < v)
        swap(u, v);
    p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int vi = 0;
    for (int i = 1; i <= M; ++i) {
        int x, u, v;
        cin >> u >> v >> x;
        village[vi++] = {x, u, v};
    }
    memset(p, -1, sizeof(p));
    sort(village, village + vi);
    int mn = 0, cnt = 0;
    if (N < 3) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < vi; ++i) {
        int cost, u, v;
        tie(cost, u, v) = village[i];
        if (!uni(u, v)) continue ;
        mn += cost;
        cnt += 1;
        if (cnt == N - 2)
            break ;
    }
    cout << mn;
}