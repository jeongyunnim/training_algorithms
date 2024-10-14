//
// Created by 서정윤 on 2024. 10. 12. 오후 10:53
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
struct info {
    int x;
    int y;
    int age;
    bool is_dead;
};
deque<int> L[11][11];

int N, M, K;
int board[11][11];
int ground[11][11];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};

void spring_and_summer() {
    int x, y;
    for (int i = 0; i < N * N; ++i) {
        x = i / N;
        y = i % N;
        size_t size = L[x][y].size();
        if (size == 0) {
            ground[x][y] += board[x][y];
            continue ;
        }
        bool is_dead = false;
        int cnt = 0;
        for (int j = 0; j < L[x][y].size(); ++j) {
            if (!is_dead && ground[x][y] >= L[x][y][j]) {
                ground[x][y] -= L[x][y][j];
                L[x][y][j] += 1;
            } else {
                is_dead = true;
                ground[x][y] += L[x][y][j] / 2;
                cnt += 1;
                continue;
            }
        }
        for (int j = 0 ; j < cnt; ++j)
            L[x][y].pop_back();
        ground[x][y] += board[x][y];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i / N][i % N];
        ground[i / N][i % N] = 5;
    }
    int x, y ,age;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> age;
        L[x - 1][y - 1].push_back(age);
    }
    while (K--) {
        spring_and_summer();
        for (int i = 0; i < N * N; ++i) {
            x = i / N;
            y = i % N;
            for (auto it : L[x][y]) {
                if (it % 5 == 0) {
                    for (int k = 0; k < 8; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        L[nx][ny].push_front(1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N * N; ++i) {
        ans += L[i / N][i % N].size();
    }
    cout << ans;
}