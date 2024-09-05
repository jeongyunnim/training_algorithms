//
// Created by 서정윤 on 2024. 9. 4..
//
#include <iostream>
#include <queue>

using namespace std;

int N;
bool board[10][10];
bool put[10][10];
bool is_used_up[20]; // 2n - 1 개
bool is_used_down[20];
int max_b;
int max_w;

void print_visited() {
    cout << "[visited]\n";
    for (int i = 0; i < N * N; ++i) {
        if (!board[i/N][i%N])
            cout << 'X';
        else
            cout << put[i/N][i%N];
        if (i%N == N-1)
            cout << '\n';
        else
            cout << ' ';
    }
}

void recursive_count(int n, int pos, bool is_black) {
    if (pos >= N * N) {
        if (is_black && max_b < n) {
//            print_visited();
            max_b = n;
        }
        else if (!is_black && max_w < n){
//            print_visited();
            max_w = n;
        }
        return ;
    }
    int x = pos / N;
    int y = pos % N;
    int next = 2;

    if (N % 2)
        next = 2;
    else if (y == N - 2)
        next = 3;
    else if (y == N - 1)
        next = 1;

    if (board[x][y] && !is_used_up[x+y] && !is_used_down[x-y+N-1]) {
        is_used_up[x + y] = true;
        is_used_down[x - y + N - 1] = true;
        put[x][y] = true;
        recursive_count(n + 1, pos + next, is_black); // 놓기
        put[x][y] = false;
        is_used_up[x + y] = false;
        is_used_down[x - y + N - 1] = false;
    }
    recursive_count(n, pos + next, is_black); // 안 놓기
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i) {
        cin >> board[i/N][i%N];
    }

    recursive_count(0, 0, true);
    recursive_count(0, 1, false);
//    cout << max_b << " + " <<  max_w << '\n';
    cout << max_b + max_w;
}