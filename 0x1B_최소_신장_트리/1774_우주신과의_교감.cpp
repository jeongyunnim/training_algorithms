//
// Created by 서정윤 on 2025. 1. 6. 오전 11:47
//
#include <bits/stdc++.h>

using namespace std;
tuple<double, int, int> god[1001 * 1001]; // dist, u, v
pair<int, int> coord[1001];
int p[1001];
int N, M;
int co_i = 0;

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
    p[u] = v;
    return true;
}

double cal_dist(long long ix, long long iy, long long jx, long long jy) {
    return sqrt(((ix - jx) * (ix - jx)) + ((iy - jy) * (iy - jy)));
}

void find_min() {
    for (int i = 1; i < N; ++i) {
        int ix, iy;
        tie(ix, iy) = coord[i];
        for (int j = i + 1; j <= N; ++j) {
            if (i == j) continue ;
            int jx, jy;
            tie(jx, jy) = coord[j];
            double dist = cal_dist(ix, iy, jx, jy); //좌표가 1000000일 수 있기 때문에 int로는 제곱 연산이 제대로 동작하지 않는다.
            god[co_i++] = {dist, i, j}; // 전부 넣어줘야 한다.
        }
    }
    sort(god, god + co_i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    memset(p, -1, sizeof(p));
    for (int i = 1; i <= N; ++i) {
        int x, y;
        cin >> x >> y;
        coord[i] = {x, y};
    }
    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin >> u >> v;
        uni(u, v);
    }
    find_min();
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < co_i; ++i) {
        double dist;
        int u, v;

        tie(dist, u, v) = god[i];
        if (!uni(u, v)) continue ;
        sum += dist;
        cnt += 1;
        if (cnt == N - 1)
            break ;
    }
    cout.precision(2);
    cout << fixed << sum;
}
