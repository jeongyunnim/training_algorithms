//
// Created by 서정윤 on 2024. 8. 23..
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_VAL 100001

int visited[MAX_VAL];
queue<int> Q;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;

    Q.push(N);
    visited[N] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < 3; i++) {
            int nx;

            if (i == 0)
                nx = cur - 1;
            else if (i == 1)
                nx = cur + 1;
            else
                nx = cur * 2;
            if (nx < 0 || nx >= MAX_VAL || visited[nx] != 0) continue;
            if (nx == K) {
                cout << visited[cur];
                return 0;
            }
            visited[nx] = visited[cur] + 1;
            Q.push(nx);
        }
    }
    cout << 0; // 동일할 경우를 생각해주었어야 했다.
    return 0;
}