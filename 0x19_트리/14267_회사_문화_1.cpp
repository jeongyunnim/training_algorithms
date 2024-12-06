//
// Created by 서정윤 on 2024. 12. 6. 오전 11:13
//
#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
int workers[1001];
int praises[1001];
int indegrees[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    queue<int> Q;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> workers[i];
        if (workers[i] == -1) {
            Q.push(i);
            continue ;
        }
        workers[i] -= 1;
        adj[workers[i]].push_back(i);
        indegrees[i] += 1;
    }
    for (int i = 0; i < M; ++i) {
        int num, amount;
        cin >> num >> amount;
        praises[num - 1] += amount;
    }
    int sum = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        sum = praises[cur];
        for (auto outdegree : adj[cur]) {
            indegrees[outdegree] -= 1;
            praises[outdegree] += sum;
            if (indegrees[outdegree] == 0) {
                Q.push(outdegree);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << praises[i] << " ";
    }

}