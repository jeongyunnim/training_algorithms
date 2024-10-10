//
// Created by 서정윤 on 2024. 10. 10. 오후 4:57
//
#include <bits/stdc++.h>

using namespace std;
int visited[200001];
int dx[2] = {-1, 1};
queue<int> Q;
int main() {

    int N, K;

    cin >> N >> K;

    if (N == K) {
        cout << 0;
        return 0;
    }
    Q.push(N);
    visited[N] = 1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = cur; i < K * 2; i += i) {
            if (i == 0) break ;
            if (visited[i]) continue ;
            if (i == K) {
                cout << visited[cur] - 1;
                return 0;
            }
            visited[i] = visited[cur];
            Q.push(i);
        }
        for (int i = 0; i < 2; ++i) {
            int nx = cur + dx[i];
            if (nx < 0) continue ;
            if (visited[nx]) continue ;
            if (nx == K) {
                cout << visited[cur];
                return 0;
            }
            visited[nx] = visited[cur] + 1;
            Q.push(nx);
        }
    }
    cout << visited[K];
}