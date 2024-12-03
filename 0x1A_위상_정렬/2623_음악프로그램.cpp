//
// Created by 서정윤 on 2024. 12. 3. 오후 7:20
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100001];
int topological[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int singer_cnt, pre = -1, num;
        cin >> singer_cnt;
        for (int j = 0; j < singer_cnt; ++j) {
            cin >> num;
            if (pre != -1) {
                adj[pre].push_back(num);
                topological[num] += 1;
            }
            pre = num;
        }
    }
    queue<int> Q;
    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        if (topological[i] == 0)
            Q.push(i);
    }
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        N--;
        ans.push_back(cur);
        for (auto outdegree : adj[cur]) {
            topological[outdegree] -= 1;
            if (topological[outdegree] == 0)
                Q.push(outdegree);
        }
    }

    if (N == 0)
        for (auto el : ans) cout << el << '\n';
    else
        cout << 0;
}