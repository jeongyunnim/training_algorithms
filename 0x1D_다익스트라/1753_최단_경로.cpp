//
// Created by 서정윤 on 2025. 3. 17. 오후 9:47
//
#include <bits/stdc++.h>
#define MAX 0x7f7f7f7f
using namespace std;
int D[20001];
int visited[20001];
vector<pair<int, int> > adj[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;
int V, E, K;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> K;
    memset(D, MAX, sizeof D);
    D[K] = 0;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    PQ.push({D[K], K});
    while (!PQ.empty())
    {
        auto cur = PQ.top();
        PQ.pop();
        if (cur.first != D[cur.second]) continue ;
        for (auto nxt : adj[cur.second])
        {
            if (nxt.first + D[cur.second] >= D[nxt.second]) continue ;
            D[nxt.second] = nxt.first + D[cur.second];
            PQ.push({D[nxt.second], nxt.second});
        }

    }
    for (int i = 1; i <= V; ++i)
    {
        if (D[i] != MAX)
            cout << D[i] << '\n';
        else
            cout << "INF\n";
    }
}