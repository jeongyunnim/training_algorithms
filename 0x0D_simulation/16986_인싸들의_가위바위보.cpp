//
// Created by 서정윤 on 2024. 12. 17. 오후 1:48
//
#include <bits/stdc++.h>

using namespace std;
int N, K;
int hand[10][10];
int seq[3][21];
int seq_i[3];
bool is_used[10];
bool is_possible;

void init() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> hand[i][j];
        }
    }
    for (int i = 1; i <= 20; ++i) {
        cin >> seq[1][i];
    }
    for (int i = 1; i <= 20; ++i) {
        cin >> seq[2][i];
    }
}

void print_name(int name) {
    switch (name) {
        case 0:
            cout << "A: ";
            break;
        case 1:
            cout << "B: ";
            break ;
        case 2:
            cout << "C: ";
    }
}

bool check() {
    int score[3];
    int pre = 0, post = 1, left = 2;
    int round = 0;

    memset(score, 0, sizeof(score));
    memset(seq_i, 0, sizeof(seq_i));
    while (score[0] < K && score[1] < K && score[2] < K) {
        // --------------------
        round += 1;
//        cout << "round " << round << '\n';
        // --------------------
        int le = seq[pre][++seq_i[pre]];
        int ri = seq[post][++seq_i[post]];
        if (seq_i[0] > N || seq_i[1] > 20 || seq_i[2] > 20) return false;
//        print_name(pre);
//        cout << le << '\n';
//        print_name(post);
//        cout << ri << '\n';
//
//        cout << "le, ri => " << hand[le][ri] << '\n';
        if (hand[le][ri] == 2) {
            score[pre] += 1;
            swap(post, left);
        } else if (hand[le][ri] == 1) {
            if (pre < post) {
                score[post] += 1;
                swap(pre, left);
                swap(post, pre);
            } else {
                score[pre] += 1;
                swap(post, left);
            }
        }
        else {
            score[post] += 1;
            swap(pre, left);
            swap(pre, post);
        }
//        cout << "current score: " << score[0] << " " << score[1] << " " << score[2] << '\n';
    }
    if (score[0] == K)
        return true;
    else
        return false;
}

void solve(int n) {
    if (n == N + 1) {
//        cout << "---------------- ";
//        for (int i = 1; i <= N; ++i) {
//            cout << seq[0][i] << " ";
//        }
//        cout << '\n';
        if (!is_possible && check())
            is_possible = true;
        return ;
    }
    for (int i = 1; i <= N; ++i) {
        if (is_used[i] || is_possible) continue ;
        is_used[i] = true;
        seq[0][n] = i;
        solve(n + 1);
        is_used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve(1);
    cout << is_possible;
}