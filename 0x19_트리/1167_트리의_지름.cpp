//
// Created by 서정윤 on 2024. 12. 19. 오후 1:29
//
#include <bits/stdc++.h>

using namespace std;
set<pair<int, int> > adj[100001];
long long dp[100001];
long long mx;

int DFS(int cur, int par) {
    priority_queue<long long, vector<long long>, greater<long long> > Q;
    for (auto child : adj[cur]) {
        if (child.first == par) continue ;
        int len = DFS(child.first, cur) + child.second;
        if (Q.size() < 2) {
            Q.push(len);
        } else {
            Q.push(len); // Q.pop과 위치가 바뀌면 안된다.
            Q.pop();
        }
    }
    if (Q.empty()) {
        return 0;
    } else if (Q.size() < 2) {
        mx = max(mx, Q.top());
        return Q.top();
    } else {
        long long secondary = Q.top();
        Q.pop();
        mx = max(mx, secondary + Q.top());
        return Q.top();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, root = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num, u = 0, cost;
        cin >> num;
        if (!root)
            root = num;
        while (true) {
            cin >> u;
            if (u == -1)
                break ;
            cin >> cost;
            adj[num].insert({u, cost});
            adj[u].insert({num, cost});
        }
    }
    DFS(root, -1);
    cout << mx;
}