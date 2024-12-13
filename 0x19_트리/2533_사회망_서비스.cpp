//
// Created by 서정윤 on 2024. 12. 13. 오후 5:46
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1000001];
int dp[1000001][2];

void DFS(int cur, int par) {
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (auto child : adj[cur]) {
        if (child == par) continue ;
        DFS(child, cur);
        dp[cur][0] += dp[child][1];
        dp[cur][1] += min(dp[child][0], dp[child][1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;

        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, -1);
    cout << min(dp[1][0], dp[1][1]); // 재귀로 돌기 때문에 mx 변수를 두지 않고 임의로 설정한 루트 노드에 대한 결괏값을 조회하면 된다.
}