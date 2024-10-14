//
// Created by 서정윤 on 2024. 10. 14. 오후 2:02
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int N;
int sea[21][21];
int visited[21][21];
int eat_cnt = 0;
pair<int, int> baby;
int age = 2;
int sec;


int call_mom() {
    queue<pair<int, int> > Q;
    vector<pair<int, int> > V;

    bzero(visited, sizeof(visited));
    Q.push({baby.X, baby.Y});
    visited[baby.X][baby.Y] = 1;
    int pre = 1;
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        if (pre != visited[cur.X][cur.Y]) {
            if (V.size() > 0) {
                pair<int, int> prior = {V[0].X, V[0].Y};
                for (int i = 1; i < V.size(); ++i) {
                    if (prior.X > V[i].X) {
                        prior = V[i];
                    } else if (prior.X == V[i].X && prior.Y > V[i].Y) {
                        prior = V[i];
                    }
                }
                sea[prior.X][prior.Y] = 0;
                if (++eat_cnt == age) {
                    eat_cnt = 0;
                    age += 1;
                }
                baby = {prior.X, prior.Y};
                return visited[prior.X][prior.Y] - 1;
            }
        }
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue ;
            if (visited[nx][ny] != 0) continue ;
            if (sea[nx][ny] > age) continue ;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            if (sea[nx][ny] != 0 && sea[nx][ny] < age) {
                V.push_back({nx, ny});
            }
            Q.push({nx, ny});
        }
        pre = visited[cur.X][cur.Y];
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i) {
        cin >> sea[i / N][i % N];
        if (sea[i / N][i % N] == 9) {
            sea[i / N][i % N] = 0;
            baby = {i / N, i % N};
        }
    }

    while (true) {
        int move = call_mom();
        if (move == 0) {
            break ;
        } else {
//            cout << "[visited]\n";
//            for (int j = 0; j < N * N; ++j) {
//                if (j / N == baby.X && j % N == baby.Y)
//                    cout << "🦈";
//                else
//                    cout << visited[j / N][j % N] << " ";
//                if (j % N == N - 1) cout << '\n';
//            }
//            cout << "[sea]\n";
//            for (int j = 0; j < N * N; ++j) {
//                if (j / N == baby.X && j % N == baby.Y)
//                    cout << "🦈";
//                else
//                    cout << sea[j / N][j % N] << " ";
//                if (j % N == N - 1) cout << '\n';
//            }
//            cout << sec << " [sec에 더한다]: ";
//            cout << move << " = " << sec + move << "\n";
            sec += move;
        }
    }
    cout << sec;
}