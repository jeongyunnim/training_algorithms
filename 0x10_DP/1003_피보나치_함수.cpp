//
// Created by 서정윤 on 2024. 9. 23. 오후 11:25
//
#include <iostream>

using namespace std;

int seq[41][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    seq[0][0] = 1;
    seq[1][1] = 1;
    seq[2][0] = 1;
    seq[2][1] = 1;
    for (int i = 3; i <= 40; ++i) {
        seq[i][0] = seq[i - 1][0];
        seq[i][0] += seq[i - 2][0];
        seq[i][1] = seq[i - 1][1];
        seq[i][1] += seq[i - 2][1];
    }

    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        cout << seq[x][0] << " " << seq[x][1] << '\n';
    }
}