//
// Created by 서정윤 on 2024. 10. 29. 오후 1:04
//
#include <bits/stdc++.h>
#define X first
using namespace std;
int N, K;
bool visited[500001][2];
int dx[2] = {-1, 1};

int get_triangle_number(int t) {
    return ((t * (t + 1)) / 2);
}

int BFS() {
    queue<pair<int, int> > Q;
    Q.push({N, 1});
    Q.push({K + 1, -1});
    visited[N][0] = 1;
    int weight = 2;
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        int time = cur.second;
        Q.pop();
        if (time < 0) {
            // check
            if (visited[cur.X][(-1 * time) % 2]) {
                return -1 * time;
            }
            if (cur.X + weight > 500000)
                return -1;
            Q.push({cur.X + weight, time - 1});
            weight += 1;
            continue ;
        }
        for (int i = 0; i < 3; ++i) {
            int nx;
            if (i == 2)
                nx = cur.X * 2;
            else
                nx = cur.X + dx[i];
            if (nx < 0 || nx > 500000 || visited[nx][time % 2]) continue ;
//            cout << time << "s " << nx << "[" << time % 2 << "]\n";
            visited[nx][time % 2] = 1;
            Q.push({nx, time + 1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }
    int res = BFS();
    if (res == -1)
        cout << -1;
    else
        cout << res;
}