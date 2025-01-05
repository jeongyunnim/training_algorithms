//
// Created by 서정윤 on 2025. 1. 5. 오후 2:11
//
#include <bits/stdc++.h>

using namespace std;
int circle[51][51];
bool visited[51][51];
int rotated[51];
int N, M, T;

//void print() {
//    for (int i = 1; i <= N; ++i) {
//        cout << "cirnum[" << i << "]: ";
//        for (int j = 0; j < M; ++j) {
//            int num = (j + rotated[i]) % M;
//            cout << circle[i][num] << " ";
//        }
//        cout << '\n';
//    }
//}

void rotate(int x, int d, int k) {
    for (int i = x; i <= N; i += x) {
//        cout << "rotate: " << i << '\n';
        if (d == 1)
            rotated[i] = (rotated[i] + k) % M;
        else
            rotated[i] = (rotated[i] + (M - k)) % M;
    }
}

int cal_rotated_num(int cir_num, int num) {
    return (rotated[cir_num] + num) % M;
}

bool remove_adj(int cir, int num) { // DFS 방식에서 BFS 방식으로 전환
    queue<pair<int, int> > Q;

    int num_p = cal_rotated_num(cir, num);
    int target = circle[cir][num_p];
    bool is_removed = false;

    if (target == 0 || visited[cir][num_p]) return false; // 이미 방문한 노드 처리 누락
    Q.push(make_pair(cir, num));
    visited[cir][num_p] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first;
            int ny = cur.second;
            if (i == 0) {
                ny = (cur.second + 1) % M;
            } else if (i == 1) {
                ny = (cur.second + M - 1) % M;
            } else if (i == 2) {
                nx = cur.first - 1;
            } else {
                nx = cur.first + 1;
            }
            if (nx == 0 || nx == N + 1) continue ; // N을 M으로 잘못 표기
            int cur_p = cal_rotated_num(nx, ny);
            if (visited[nx][cur_p] || circle[nx][cur_p] == 0 || circle[nx][cur_p] != target) continue ;
            circle[nx][cur_p] = 0;
            is_removed = true;
            visited[nx][cur_p] = true;
            Q.push({nx, ny});
        }
    }
    if (is_removed)
        circle[cir][num_p] = 0;
    return is_removed;
}

int cal() {
    bool is_removed = false;

    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (remove_adj(i, j))
                is_removed = true;
        }
    }
    int total = 0, sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (circle[i][j] == 0) continue ;
            total += 1;
            sum += circle[i][j];
        }
    }
    if (total && !is_removed) { // div by zero를 처리하지 못했다.
        double avg = (double)sum / (double)total;
        sum = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (circle[i][j] == 0) continue ;
                if (avg < circle[i][j]) {
                    circle[i][j] -= 1;
                } else if (avg > circle[i][j]) {
                    circle[i][j] += 1;
                }
                sum += circle[i][j];
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> circle[i][j];
        }
    }
    int res;
    for (int i = 0; i < T; ++i) {
        int x, d, k;
        cin >> x >> d >> k;
        // x의 배수 d방향으로 k만큼 회전
        rotate(x, d, k);
        res = cal();
    }
    cout << res;
}