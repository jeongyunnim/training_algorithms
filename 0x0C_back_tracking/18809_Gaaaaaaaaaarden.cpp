//
// Created by 서정윤 on 2024. 9. 4..
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>

# define X first
# define Y second
# define GRN 1
# define RED 2
# define FLW 3

using namespace std;

int M, N, G, R;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,1, 0, -1};
int board[51][51];
int visited[51][51];
//int visited_r[51][51]; green과 red는 같은 맵을 써야 한다.

int avail[11][2];
int avail_len;

int issued[11];
int green_pos[6][2];
int red_pos[6][2];
int mx;

queue<pair<int, int> > Qg;
queue<pair<int, int> > Qr;

void BFS() {
    // init
    for (int i = 0; i < M; ++i)
        bzero(visited[i], sizeof(visited[i]));

    Qg = queue<pair<int, int> >();
    Qr = queue<pair<int, int> >();
    vector<pair<int, int> > can_bloom;
    int cnt = 0;

    for (int i = 0; i < G; ++i) {
        Qg.push(make_pair(green_pos[i][0], green_pos[i][1]));
        visited[green_pos[i][0]][green_pos[i][1]] = GRN;
    }
    for (int i = 0; i < R; ++i) {
        Qr.push(make_pair(red_pos[i][0], red_pos[i][1]));
        visited[red_pos[i][0]][red_pos[i][1]] = RED;
    }

    while (!Qg.empty() || !Qr.empty()) {
        pair<int, int> cur;
        int cur_size = Qg.size();
        can_bloom.clear();
        while (cur_size--) {
            cur = Qg.front(); Qg.pop();
            if (visited[cur.X][cur.Y] == FLW) continue ;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue ;
                if (board[nx][ny] == 0 || visited[nx][ny] != 0) continue ;
                visited[nx][ny] = GRN;
                Qg.push({nx, ny});
                can_bloom.push_back({nx, ny});
            }
        }
        cur_size = Qr.size();
        while (cur_size--) {
            cur = Qr.front(); Qr.pop();
            if (visited[cur.X][cur.Y] == FLW) continue ;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue ;
                if (visited[nx][ny] == GRN && find(can_bloom.begin(), can_bloom.end(), make_pair(nx, ny)) != can_bloom.end()) {
                    visited[nx][ny] = FLW;
                    cnt += 1;
                    continue ;
                }
                if (board[nx][ny] == 0 || visited[nx][ny] != 0) continue ;
                visited[nx][ny] = RED;
                Qr.push({nx, ny});
            }
        }
    }
    if (mx < cnt)
        mx = cnt;
}

void recursive_feed_red(int cur, int pos) {
    if (cur == R) {
        BFS();
        return ;
    }
    for (int i = pos; i < avail_len; ++i) {
        if (issued[i]) continue ;
        issued[i] = true;
        red_pos[cur][0] = avail[i][0];
        red_pos[cur][1] = avail[i][1];
        recursive_feed_red(cur + 1, i);
        issued[i] = false;
    }
}

void recursive_feed_green(int cur, int pos) {
    if (cur == G) {
        recursive_feed_red(0, 0);
        return ;
    }

    for (int i = pos; i < avail_len; ++i) {
        if (issued[i]) continue ;
        issued[i] = true;
        green_pos[cur][0] = avail[i][0];
        green_pos[cur][1] = avail[i][1];
        recursive_feed_green(cur + 1, i);
        issued[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> G >> R;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                avail[avail_len][0] = i;
                avail[avail_len][1] = j;
                avail_len += 1;
            }
        }
    }
    recursive_feed_green(0, 0);
    cout << mx;
}