//
// Created by 서정윤 on 2025. 1. 31. 오전 8:46
//
#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff / 2;
int board[101][101];
int trace[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        fill(board[i] + 1, board[i] + N + 1, INF);
    }
    for (int i = 0; i < M; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        if (board[u][v] > cost) {
            board[u][v] = cost;
            trace[u][v] = v;
        }
    }
    for (int i = 1; i <= N; ++i) {
        board[i][i] = 0;
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (board[i][j] > board[i][k] + board[k][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                    trace[i][j] = trace[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (board[i][j] == INF) {
                cout << "0 ";
            } else {
                cout << board[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    int history[101], his_i;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            his_i = 0;
            if (i == j || board[i][j] == INF) {
                cout << "0\n";
            } else {
                history[his_i++] = i;
                for (int cur = trace[i][j]; cur != j; cur = trace[cur][j]) {
                    history[his_i] = cur;
                    his_i += 1;
                }
                history[his_i++] = j;
                cout << his_i << ' ';
                for (int his_j = 0; his_j < his_i; ++his_j) {
                    cout << history[his_j];
                    if (his_j == his_i - 1)
                        cout << '\n';
                    else
                        cout << ' ';
                }
            }
        }
    }
}