//
// Created by 서정윤 on 2024. 10. 31. 오후 12:37
//
#include <bits/stdc++.h>
#define X first
#define Y second

typedef struct info {
    int x;
    int y;
} info;

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, area = 3;
char lake[1501][1501];
int visited[1501][1501];
int area_info[1500 * 750 + 1];
queue<info> Q;
queue<info> WQ;

int get_root(int t) {
    int next = t;
    while (area_info[next] != 0) {
        next = area_info[next];
    }
    return next;
}

bool BFS_swan() {
    queue<info> TQ;
    while (!Q.empty()) {
        auto cur = Q.front();

        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (visited[nx][ny] != 0 && lake[nx][ny] != 'X' && visited[nx][ny] != visited[cur.x][cur.y]) {
                visited[nx][ny] = visited[cur.x][cur.y];
                return true;
            }
            if (visited[nx][ny]) continue ;
            visited[nx][ny] = visited[cur.x][cur.y];
            if (lake[nx][ny] == 'X') {
                TQ.push({nx, ny});
            } else {
                Q.push({nx, ny});
            }
        }
    }
    Q = TQ;
    return false;
}

void melt() {
    int sz = WQ.size();
    while (sz--) {
        auto cur = WQ.front();
        WQ.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (lake[nx][ny] != 'X') continue ;
            WQ.push({nx, ny});
            lake[nx][ny] = '.';
        }
    }
}

void print_info(int day) {
    cout << "[day " << day << "]\n";
    for (int i = 0; i < N * M; ++i) {
        if (lake[i / M][i % M] == 'X') {
            cout << "* ";
        } else if (visited[i / M][i % M] == 0) {
            cout << ". ";
        } else {
            cout << visited[i / M][i % M] << " ";
        }
        if (i % M == M - 1) cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int swan_i = 1;
    for (int i = 0; i < N * M; ++i) {
        cin >> lake[i / M][i % M];
        if (lake[i / M][i % M] == 'L') {
            Q.push({i / M, i % M});
            WQ.push({i / M, i % M});
            visited[i / M][i % M] = swan_i++;
        } else if (lake[i / M][i % M] == '.') {
            WQ.push({i / M, i % M});
        }
    }
    int day = 0;
    while (true) {
        if (BFS_swan())
            break ;
//        print_info(day);
        melt();
        day += 1;
    }
    cout << day;
}
