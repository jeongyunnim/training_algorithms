//
// Created by 서정윤 on 2024. 10. 9. 오후 6:15
//
#include <bits/stdc++.h>

using namespace std;
int T, N;
int input[100001];
int visited[100001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        bzero(visited, sizeof(visited));
        int cnt = N;
        for (int i = 1; i <= N; ++i) {
            cin >> input[i];
            if (input[i] == i) {
                visited[i] = -1;
                cnt -= 1;
            }
        }
        queue<pair<int, int> > Q; // pair<member, group>
        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue ;
            Q.push({input[i], i});
            visited[i] = i;
            int find_loop = -1;
            while (!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                if (visited[cur.first]) {
                    if (visited[cur.first] == i)
                        find_loop = cur.first;
                    break ;
                }
                visited[cur.first] = i;
                Q.push({input[cur.first], i});
            }
            if (find_loop > 0) {
                int next = input[find_loop];
                cnt -= 2;
                while (input[next] != find_loop) {
                    cnt -= 1;
                    next = input[next];
                }
            }
        }
        cout << cnt << '\n';
    }
}