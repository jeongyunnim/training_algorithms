//
// Created by 서정윤 on 2024. 11. 9. 오후 5:58
//
#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> adj[51];
queue<pair<int, string> > ans;
bool visited[51];

int BFS(int i) {
    queue<pair<int, int> > Q;
    int point = 1;

    bzero(visited, sizeof(visited));
    visited[i] = 1;
    for (auto node : adj[i]) {
        Q.push({node, 1});
        visited[node] = 1;
    }
    while (!Q.empty()) {
        auto cur = Q.front();

        point = max(point, cur.second);
        Q.pop();
        for (auto node : adj[cur.first]) {
            if (visited[node]) continue ;
            Q.push({node, cur.second + 1});
            visited[node] = 1;
        }
    }
    return point;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x < 0 || y < 0)
            break ;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        // DFS 돌리고 각 depth에 맞게 점수부여
        int point = BFS(i);

        if (ans.empty()) {
            cnt = 1;
            ans.push({point, to_string(i)});
        }
        else if (ans.front().first == point) {
            ans.front().second += ' ' + to_string(i);
            cnt += 1;
        } else if (ans.front().first > point) {
            ans.pop();
            ans.push({point, to_string(i)});
            cnt = 1;
        }
    }
    cout << ans.front().first << " " << cnt << '\n' << ans.front().second;
}