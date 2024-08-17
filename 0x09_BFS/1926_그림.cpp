//
// Created by 서정윤 on 8/16/24.
//
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main () {

    int n, m;
    int mx = 0;
    int area = 0;
    int pic_count = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int, int> > Q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (board[i][j] == 0 || vis[i][j]) continue ;
            ++pic_count;
            pair<int, int> cur = {i, j};
            vis[i][j] = 1;
            Q.push(cur);
            while (!Q.empty()) {
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(area, mx);
            area = 0;
        }
    }
    cout << pic_count << "\n" << mx;
    return 0;
}
