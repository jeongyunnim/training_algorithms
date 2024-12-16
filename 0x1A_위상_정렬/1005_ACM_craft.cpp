//
// Created by 서정윤 on 2024. 12. 16. 오후 1:36
//
#include <bits/stdc++.h>

using namespace std;
int cost[1001];
vector<int> adj[1001];
int indegree[1001];
int par[1001];
int dp[1001];

int find(int x) {
    if (par[x] == -1) return x;
    else return par[x] = find(par[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        memset(indegree, 0, sizeof(indegree));
        memset(par, -1, sizeof(par));
        for (int i = 1; i <= N; ++i) {
            cin >> cost[i];
            adj[i].clear();
        }
        for (int i = 1; i <= K; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indegree[v] += 1;
        }
        int tar;

        cin >> tar;
        queue<pair<int, int> > Q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                Q.push({i, cost[i]});
                dp[i] = cost[i];
            } else {
                dp[i] = 0;
            }
        }
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if (cur.first == tar)
                break ;
            for (auto outdegree : adj[cur.first]) {
                indegree[outdegree] -= 1;
                if (!dp[outdegree]) {
                    dp[outdegree] = cur.second + cost[outdegree];
                } else {
                    dp[outdegree] = max(dp[outdegree], cur.second + cost[outdegree]);
                }
                if (indegree[outdegree] == 0) {
                    Q.push({outdegree, dp[outdegree]});
                }
            }
        }
        cout << dp[tar] << '\n';
    }
}