//
// Created by 서정윤 on 2024. 10. 10. 오후 4:57
//
#include <bits/stdc++.h>

using namespace std;
int visited[200001][2];
vector<int> ans;
queue<int> Q;
int dx[2] = {-1, 1};
int main() {

    int N, K;

    cin >> N >> K;

    if (N == K) {
        cout << "0\n" << N;
        return 0;
    }
    Q.push(N);
    visited[N][0] = 1;
    visited[N][1] = -1;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < 3; ++i) {
            // 2배 확인
            if (i == 2) {
                if (cur == 0 || cur > K) continue ;
                if (visited[cur * 2][0]) continue ;
                visited[cur * 2][0] = visited[cur][0] + 1;
                visited[cur * 2][1] = cur;
                if (cur * 2 == K)
                    break ;
                Q.push(cur * 2);
                continue ;
            }

            // 앞 뒤 확인
            int nx = cur + dx[i];
            if (nx < 0) continue ;
            if (visited[nx][0]) continue ;
            visited[nx][0] = visited[cur][0] + 1;
            visited[nx][1] = cur;
            if (nx == K) {
                break ;
            }
            Q.push(nx);
        }
        if (visited[K][0])
            break ;
    }
    cout << visited[K][0] - 1 << '\n'; // 현 위치를 1부터 시작하기 때문에 -1을 해주어야 했다.
    for (int i = K; i >= 0; i = visited[i][1]) {
        ans.push_back(i);
    }
    for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << ' ';
    }

}