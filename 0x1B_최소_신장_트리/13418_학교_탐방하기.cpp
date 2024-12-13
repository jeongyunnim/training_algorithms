//
// Created by 서정윤 on 2024. 12. 13. 오후 7:04
//
#include <bits/stdc++.h>

using namespace std;
tuple<int, int, int> roads[1000 * 999 / 2 + 1];
int p[1001];

int find(int x) {
    if (p[x] == -1) return x;
    else return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (u < v) swap(u, v);
    p[v] = u;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[i] = {c, a, b};
    }
    memset(p, -1, sizeof(p));
    sort(roads + 1, roads + M + 1);
    long long mn = 0, mx = 0;
    for (int i = 0; i <= M; ++i) {
        int cost, u, v;
        tie(cost, u, v) = roads[i];
        if (!uni(u, v)) continue ;
        if (cost == 0) // 문제를 제대로 읽자. 0일 때 오르막이다.
            mx += 1;
    }
    sort(roads + 1, roads + M + 1, greater<tuple<int, int, int> >());
    memset(p, -1, sizeof(p));
    for (int i = 0; i <= M; ++i) {
        int cost, u, v;
        tie(cost, u, v) = roads[i];
        if (!uni(u, v)) continue ;
        if (cost == 0)
            mn += 1;
    }
    cout << (mx * mx) - (mn * mn);
}