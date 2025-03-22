//
// Created by 서정윤 on 2025. 3. 21. 오전 8:46
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adj[1001];
vector<int> d(1001, 0x7f7f7f7f);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, V;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
    }
    cin >> S >> V;
    PQ.push({0, S});
    d[S] = 0;
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (d[v] != c) continue ;
        for (auto n : adj[v])
        {
            if (d[n.second] > c + n.first)
            {
                d[n.second] = c + n.first;
                PQ.push({d[n.second], n.second});
            }
        }
    }
    cout << d[V];
}
