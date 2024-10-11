//
// Created by 서정윤 on 2024. 10. 12. 오후 2:12
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int N, L, R;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int nation[51][51];
bool visited[51][51];

bool move() {
    bool is_move = false;
    bzero(visited, sizeof(visited));
    queue<pair<int, int> > Q;
    queue<pair<int, int> > Q2;
    for (int i = 0; i < N * N; ++i) {
        int x = i / N;
        int y = i % N;
        if (visited[x][y]) continue ;
        Q.push({x, y});
        visited[x][y] = true;
        Q2.push({x, y});
        int association = 1;
        int population = nation[x][y];
        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int j = 0; j < 4; ++j) {
                int nx = cur.X + dx[j];
                int ny = cur.Y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
                if (visited[nx][ny]) continue ;
                int gap = nation[nx][ny] > nation[cur.X][cur.Y] ?
                        nation[nx][ny] - nation[cur.X][cur.Y] : nation[cur.X][cur.Y] - nation[nx][ny];
                if (gap < L || R < gap) continue ;
                is_move = true;
                visited[nx][ny] = true;
                association += 1;
                population += nation[nx][ny];
                Q.push({nx, ny});
                Q2.push({nx, ny});
            }
        }
        if (association > 1) {
            int average = population / association;
            bool is_stuck = true;
            while (!Q2.empty()) {
                if (nation[Q2.front().X][Q2.front().Y] != average)
                    is_stuck = false;
                nation[Q2.front().X][Q2.front().Y] = average;
                Q2.pop();
            }
            if (is_stuck)
                is_move = false;
        } else {
            Q2.pop();
        }
    }
    return is_move;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;

    cin >> N >> L >> R;
    for (int i = 0; i < N * N; ++i) {
        cin >> nation[i / N][i % N];
    }
    while (move()) {
        cnt += 1;
    }
    cout << cnt;
}