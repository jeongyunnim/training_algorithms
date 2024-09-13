//
// Created by 서정윤 on 2024. 9. 12. 오후 4:48
//
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N, len, ans;
int map[101][101];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

void check_line(int x, int y, int dir) {
    int prev = map[x][y];
    int cnt = 1; // 핵심 로직: cnt를 통해 4개의 조건으로 모두 검사할 수 있다.
    for (int i = 1; i < N; ++i) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (map[nx][ny] == prev) cnt++;
        else if (map[nx][ny] - prev == 1 && cnt >= len) cnt = 1;
        else if (map[nx][ny] - prev == -1 && cnt >= 0) cnt = -len + 1;
        else return;
        prev = map[nx][ny];
    }
    if (cnt >= 0)
        ans += 1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> len;

    for (int i = 0; i < N * N; ++i) {
        cin >> map[i/N][i%N];
    }
    for(int i = 0; i < N; ++i) {
        check_line(0, i, 0);
        check_line(i, 0, 1);
    }
    cout << ans;
}