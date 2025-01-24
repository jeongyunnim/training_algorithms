//
// Created by 서정윤 on 2025. 1. 24. 오전 10:22
//
#include <bits/stdc++.h>

using namespace std;
tuple<float, int, int> edge[101 * 101];
int edgei;
int N;
float stars[101][2];
int p[101];

int find(int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (u < v)
        swap(u, v);
    p[v] = u;
    return true;
}

float cal_dist(float ix, float iy, float jx, float jy) {
    return sqrt((ix - jx) * (ix - jx) + (iy - jy) * (iy - jy));
}

void dist_init() {
    for (int i = 0; i < N - 1; ++i) {
        float cur;
        for (int j = i + 1; j < N; ++j) {
            cur = cal_dist(stars[i][0], stars[i][1], stars[j][0], stars[j][1]);
            edge[edgei++] = {cur, i, j};
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> stars[i][0] >> stars[i][1];
    }
    int cnt = 0;
    float total = 0;
    memset(p, -1, sizeof(p));
    dist_init();
    sort(edge, edge + edgei);
    for (int i = 0; i < edgei; ++i) {
        int u, v;
        float dist;
        tie(dist, u, v) = edge[i];
        if (!uni(u, v)) continue ;
        total += dist;
        cnt += 1;
        if (cnt == N - 1) break ;
    }
    cout << total;
}
