//
// Created by 서정윤 on 2025. 2. 11. 오후 11:35
//
//
#include <bits/stdc++.h>

using namespace std;
tuple<int, int, int> hosts[1001];
int p[1001];

int find(int x)
{
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (u > v)
        swap(u, v);
    p[u] = v;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    int hosts_i = 0;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue ;
        hosts[hosts_i++] = {c, a, b};
    }
    sort(hosts, hosts + hosts_i);
    int ans = 0, cnt = 0;
    for (int i = 0; i < hosts_i; ++i) {
        int u, v, cost;
        tie(cost, u, v) = hosts[i];
        if (!uni(u, v)) continue ;
        cnt += 1;
        ans += cost;
        if (cnt == N - 1)
            break ;
    }
    cout << ans;
    return 0;
}