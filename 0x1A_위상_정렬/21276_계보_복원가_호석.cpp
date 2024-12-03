//
// Created by 서정윤 on 2024. 12. 3. 오후 10:55
//
#include <bits/stdc++.h>

using namespace std;

map<string, int> members;
vector<pair<string, set<string> > > ans;
vector<int> adj[1001];
int indegree[1001];
int N, M;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        members[name];
    }
    int idx = 0;
    for (auto it = members.begin(); it != members.end(); ++it) {
        it->second = idx;
        ans.push_back({it->first, set<string>()});
        idx += 1;
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string pre, post;
        cin >> pre >> post;
        int pre_idx = members[pre], post_idx = members[post];
        indegree[pre_idx] += 1;
        adj[post_idx].push_back(pre_idx);
    }
    queue<int> Q;
    string roots;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            Q.push(i);
            roots += ans[i].first + " ";
        }
    }
    cout << Q.size() << '\n';
    cout << roots << '\n';

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (auto outdegree : adj[cur]) {
            indegree[outdegree] -= 1;
            if (indegree[outdegree] == 0) {
                Q.push(outdegree);
                // outdgree 중 하나가 부모가 됨.
                // 무엇을 선택해야 하는가?
                ans[cur].second.insert(ans[outdegree].first);
            }
        }
    }
    for (auto el : ans) {
        cout << el.first << " " << el.second.size() << " ";
        for (auto names : el.second) {
            cout << names << " ";
        }
        cout << '\n';
    }

}