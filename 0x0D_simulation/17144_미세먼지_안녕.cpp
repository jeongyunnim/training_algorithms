//
// Created by 서정윤 on 2024. 11. 19. 오후 5:39
//
#include <bits/stdc++.h>

using namespace std;
int board[51][51];
int cleaner[2];
int N, M, T;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void spread() {
    int temp[51][51];

    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] < 5) continue ;
            int amount = board[i][j] / 5;
            int time = 0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue ;
                if (board[nx][ny] == -1) continue ;
                temp[nx][ny] += amount;
                time += 1;
            }
            temp[i][j] -= amount * time;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            board[i][j] += temp[i][j];
        }
    }
}

void work() {
    cout << "작동 전]\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout.width(3);
            if (board[i][j] == -1) cout << left << "*";
            else
                cout << left << board[i][j];
        }
        cout << '\n';
    }

    board[cleaner[0] - 1][0] = 0;
    board[cleaner[1] + 1][0] = 0;

    // 0행
    for (int i = cleaner[0] - 1; i > 0; --i) { // i > 1로 해두어서 틀린 것...
        board[i][0] = board[i - 1][0];
    }
    for (int i = cleaner[1] + 1; i < N; ++i) {
        board[i][0] = board[i + 1][0];
    }
    // 상하단
    for (int i = 0; i < M - 1; ++i) {
        board[0][i] = board[0][i + 1];
        board[N - 1][i] = board[N - 1][i + 1];
    }
    // M - 1 행
    for (int i = 0; i < cleaner[0]; ++i) {
        board[i][M - 1] = board[i + 1][M - 1];
    }
    for (int i = N - 1; i > cleaner[1]; --i) {
        board[i][M - 1] = board[i - 1][M - 1];
    }
    // 중단
    for (int i = M - 1; i > 0; --i) {
        board[cleaner[0]][i] = board[cleaner[0]][i - 1];
        board[cleaner[1]][i] = board[cleaner[1]][i - 1];
    }
    board[cleaner[0]][1] = 0;
    board[cleaner[1]][1] = 0;
    cout << "작동 후]\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout.width(3);
            if (board[i][j] == -1) cout << left << "*";
            else
                cout << left << board[i][j];
        }
        cout << '\n';
    }
}

int total() {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == -1) continue ;
            res += board[i][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;

    int ci = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == -1)
                cleaner[ci++] = i;
        }
    }

    for (int i = 0; i < T; ++i) {
        spread();
        work();
    }
    cout << total();
}