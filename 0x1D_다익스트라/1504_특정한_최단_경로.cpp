//
// Created by 서정윤 on 2025. 3. 23. 오후 6:21
//
#include <bits/stdc++.h>
#define MAX 0x7fffffff / 3
using namespace std;
vector<pair<int, int> > adj[801];
vector<int> ds(801, MAX);
vector<int> de(801, MAX);
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > PQ;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E, S1, S2;
    cin >> N >> E;
    for (int i = 0; i < E; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    cin >> S1 >> S2;
    ds[S1] = 0;
    PQ.push({0, S1});
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (ds[v] != c) continue ;
        for (auto n : adj[v])
        {
            if (ds[n.second] > c + n.first)
            {
                ds[n.second] = c + n.first;
                PQ.push({ds[n.second], n.second});
            }
        }
    }
    de[S2] = 0;
    PQ.push({0, S2});
    while (!PQ.empty())
    {
        int c, v;
        tie(c, v) = PQ.top();
        PQ.pop();
        if (de[v] != c) continue ;
        for (auto n : adj[v])
        {
            if (de[n.second] > c + n.first)
            {
                de[n.second] = c + n.first;
                PQ.push({de[n.second], n.second});
            }
        }
    }
    int mn = 0;
    int S1_first = ds[1] + ds[S2] + de[N];
    int S2_first = de[1] + de[S1] + ds[N];
    if (S1_first < S2_first)
        mn = S1_first;
    else
        mn = S2_first;
    if (mn >= MAX)
        mn = -1;
//    cout << "start to..\n";
//    for (int i = 1; i <= N; ++i)
//    {
//        cout << ds[i] << ' ';
//    }
//    cout << "\nend to..\n";
//    for (int i = 1; i <= N; ++i)
//    {
//        cout << de[i] << ' ';
//    }
//    cout << "max: ";
    cout << mn;
}