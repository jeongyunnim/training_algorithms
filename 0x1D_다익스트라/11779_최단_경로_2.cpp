//
// Created by 서정윤 on 2025. 3. 19. 오전 10:59
//
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > adj[1001];
vector<int> trace(1001);
vector<int> least_dist(1001, 0x7f7f7f7f);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, S, E;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
    }
    cin >> S >> E;
    least_dist[S] = 0;
    PQ.push({0, S});
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (least_dist[v] != c) continue ;
        for (auto nxt : adj[v])
        {
            if (least_dist[nxt.second] > least_dist[v] + nxt.first)
            {
                least_dist[nxt.second] = least_dist[v] + nxt.first;
                trace[nxt.second] = v;
                PQ.push({least_dist[nxt.second], nxt.second});
            }
        }
    }
    int tmp = E;
    vector<int> route;
    while (tmp != S)
    {
        route.push_back(tmp);
        tmp = trace[tmp];
    }
    cout << least_dist[E] << '\n';
    cout << route.size() + 1 << '\n';
    cout << S << ' ';
    for (auto rit = route.rbegin(); rit != route.rend(); ++rit)
    {
        cout << *rit << " ";
    }
}