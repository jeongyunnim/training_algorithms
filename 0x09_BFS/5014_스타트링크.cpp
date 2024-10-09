//
// Created by 서정윤 on 2024. 10. 8. 오후 5:24
//
#include <bits/stdc++.h>

using namespace std;
int visited[1000001];
queue<int> Q;

int main() {
    int F, S, G, U, D;

    cin >> F >> S >> G >> U >> D;

    if (S == G) {
        cout << 0;
        return 0;
    }
    Q.push(S);
    int dx[2] = {U, D * -1};
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < 2; ++i) {
            if (dx[i] == 0) continue ;
            int nx = cur + dx[i];
            if (nx <= 0 || nx > F) continue ;
            if (visited[nx]) continue ;
            visited[nx] = visited[cur] + 1;
            if (nx == G) {
                cout << visited[nx];
                return 0;
            }
            Q.push(nx);
        }
    }
    cout << "use the stairs";
}