//
// Created by 서정윤 on 2024. 12. 9. 오후 4:25
//
#include <bits/stdc++.h>

using namespace std;
tuple<int, int, int> planets[1001 * 1001];
int p[1001];

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

    int N;
    cin >> N;
    int pi = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            if (i < j)
                planets[pi++] = {x, i, j};
        }
    }
    memset(p, -1, sizeof(p));
    sort(planets, planets + pi);
    int mn = 0;
    for (int i = 0; i < pi; ++i) {
        int cost, u, v;
        tie(cost, u, v) = planets[i];
        if (!uni(u, v)) continue ;
        mn += cost;
    }
    cout << mn;
}