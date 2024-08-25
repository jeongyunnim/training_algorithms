//
// Created by 서정윤 on 2024. 8. 24..
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define X first
#define Y second

using namespace std;
#define MAX_VAL 101
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, sum;
char pic[MAX_VAL][MAX_VAL];
bool visited[MAX_VAL][MAX_VAL];
queue<pair<int, int> > Q;

void search(int i, int j, char c) {
    Q.push({i, j});
    visited[i][j] = true;
    while (!Q.empty()) {
        pair<int ,int> cur = Q.front(); Q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (pic[nx][ny] != c || visited[nx][ny]) continue ;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    char c;

    for (int i = 0; i < N; i++) {
        cin >> pic[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c = pic[i][j];
            if (c == 'G') pic[i][j] = 'R';
            if (visited[i][j]) continue ;
            sum += 1;
            search(i, j, c);
        }
    }

    cout << sum << ' ';
    sum = 0;
    bzero(visited, sizeof(visited));
    Q = queue<pair<int, int> >();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c = pic[i][j];
            if (visited[i][j]) continue ;
            sum += 1;
            search(i, j, c);
        }
    }
    cout << sum;
    return 0;
}