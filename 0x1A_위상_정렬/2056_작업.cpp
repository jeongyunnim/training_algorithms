//
// Created by 서정윤 on 2024. 12. 11. 오후 4:18
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[10001];
int indegrees[10001];
int require[10001];
int dp[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    queue<int> Q;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int t, num, d;
        cin >> t >> num;
        require[i] = t;
        for (int j = 1; j <= num; ++j) {
            cin >> d;
            adj[i].push_back(d);
            indegrees[d] += 1;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (!indegrees[i]) {
            Q.push(i);
            dp[i] = require[i];
        }
    }
    int ans = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto outdegree : adj[cur]) {
            indegrees[outdegree] -= 1;
            dp[outdegree] = max(dp[outdegree], dp[cur] + require[outdegree]);
            if (indegrees[outdegree] == 0) {
                Q.push(outdegree);
            }
        }
        ans = max(ans, dp[cur]);
    }
    cout << ans;
}

/*
8
1 0
2 1 1
3 1 1
4 1 1
5 1 1
6 0
7 1 6
8 1 6
*/