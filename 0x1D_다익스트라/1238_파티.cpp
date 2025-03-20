//
// Created by 서정윤 on 2025. 3. 20. 오전 11:06
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adj[1001];
vector<pair<int, int> > adj_rev[1001];
vector<int> d(1001, 0x7f7f7f7f);
vector<int> d_rev(1001, 0x7f7f7f7f);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj_rev[v].push_back({c, u});
    }
    d[X] = 0;
    d_rev[X] = 0;
    PQ.push({0, X});
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (d[v] != c) continue ;
        for (auto n : adj[v])
        {
            if (d[n.second] > n.first + c)
            {
                d[n.second] = n.first + c;
                PQ.push({n.first + c, n.second});
            }
        }
    }
    PQ.push({0, X});
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (d_rev[v] != c) continue ;
        for (auto n : adj_rev[v])
        {
            if (d_rev[n.second] > n.first + c)
            {
                d_rev[n.second] = n.first + c;
                PQ.push({n.first + c, n.second});
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (mx < d[i] + d_rev[i])
            mx = d[i] + d_rev[i];
    }
    cout << mx;
}