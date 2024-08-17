//
// Created by 서정윤 on 8/17/24.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
#define MAX_VAL 102

int board[MAX_VAL][MAX_VAL];
int dist[MAX_VAL][MAX_VAL];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {

    ios::sync_with_stdio(0);
    string input_string;
    cin.tie(0);

    queue<pair<int, int> > Q;
    int n ,m, current_dist = 1;
    cin >> n >> m;

    for (int i=0;i<n;i++) {
        cin >> input_string;
        for (int j=0;j<m;j++){
            board[i][j] = input_string[j] - '0';
        }
    }
    for (int i=0;i < n; i++)
        fill(dist[i], dist[i] + m, -1);
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            if (nx == n - 1 && ny == m - 1){
                cout << dist[nx][ny];
                return 0;
            }
            Q.push({nx, ny});
        }
    }
    return 0;
}