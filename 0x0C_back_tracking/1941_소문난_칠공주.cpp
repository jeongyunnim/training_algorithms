//
// Created by 서정윤 on 2024. 9. 5..
//
#include <iostream>
#include <queue>
#include <cstring>

# define X first
# define Y second

using namespace std;

queue<pair<int, int> > Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,1, 0, -1};
int princesses[7][2];
int cnt;
char students[6][6];
int visited[5][5];

bool is_adjacent() {
    int member_cnt = 0; // 초기화를 잊지 말자.

    for (int i = 0; i < 5; ++i) {
        bzero(visited, sizeof(visited));
    }
    for (int i = 0; i < 7; ++i) {
        visited[princesses[i][0]][princesses[i][1]] = 1;
    }
    Q.push({princesses[0][0], princesses[0][1]});

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue ;
            if (visited[nx][ny] == 0 || visited[nx][ny] == 2) continue ;
            visited[nx][ny] = 2;
            Q.push({nx,ny});
            member_cnt += 1;
        }
    }

    if (member_cnt != 7)
        return false;
    else {
        return true;
    }
}

bool check_rule() {
    int s = 0;
    for (int i = 0; i < 7; ++i) {
        if (students[princesses[i][0]][princesses[i][1]] == 'S')
            s += 1;
        if (s > 3)
            return true;
    }

    return false;
}

void recursive_comb(int n, int pos) {
    if (pos > 25) return ; // 탈출 조건은 24가 호출한 25이다.
    if (n == 7) {
        // bfs
        if (check_rule() && is_adjacent())
            cnt += 1;
        return ;
    }
    int x = pos / 5;
    int y = pos % 5;
    princesses[n][0] = x;
    princesses[n][1] = y;
    recursive_comb(n + 1, pos + 1);
    recursive_comb(n, pos + 1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; ++i) {
        cin >> students[i];
    }
    recursive_comb(0, 0);
    cout << cnt;
}