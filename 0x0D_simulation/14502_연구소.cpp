
//
// Created by 서정윤 on 2024. 9. 10. 오후 5:27
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define X first
#define Y second

using namespace std;

queue<pair<int, int> > Q;
int N, M, blanks, mx;
int map[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> walls[3];
bool visited[9][9];

void BFS() {
    queue<pair<int, int> > TQ = Q;
    int viruses = 0;
    for (int i = 0; i < N; ++i)
        bzero(visited[i], sizeof(visited[i]));
    while (!TQ.empty()) {
        pair<int, int> cur = TQ.front();
        if (mx > blanks - viruses - 3)
            return ;
        TQ.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
            if (map[nx][ny] != 0) continue ;
            if (visited[nx][ny]) continue ;
            visited[nx][ny] = true;
            viruses += 1;
            TQ.emplace(nx, ny);
        }
    }
//    cout << "\n아래 결과 " << blanks << " - " << viruses << '\n';
    mx = max(mx, blanks - viruses - 3);
}

void recursive_compose(int n, int pos) {
    if (pos > N * M) // 마지막에 들어온 녀석을 해줘야지
        return ;
    if (n == 3) {
        map[walls[0].X][walls[0].Y] = 1;
        map[walls[1].X][walls[1].Y] = 1;
        map[walls[2].X][walls[2].Y] = 1;

        BFS();

        map[walls[0].X][walls[0].Y] = 0;
        map[walls[1].X][walls[1].Y] = 0;
        map[walls[2].X][walls[2].Y] = 0;
        return ;
    }

    int x = pos / M;
    int y = pos % M;
    walls[n] = {x, y};
    if (map[x][y] == 0)
        recursive_compose(n + 1, pos + 1);
    recursive_compose(n, pos + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2)
                Q.emplace(i, j);
            else if (map[i][j] == 0)
                blanks += 1;
        }
    }
    recursive_compose(0, 0);
    cout << mx;
}