//
// Created by 서정윤 on 2024. 9. 12. 오후 2:56
//
#include <iostream>
#include <cmath>

using namespace std;

int N, mn = INT32_MAX;
int table[21][21];
int group1[21];
int group2[21];

void cal_points() {
    int s = 0, l = 0;
    for (int i = 0; i < N / 2 - 1; ++i) {
        for (int j = i + 1; j < N / 2; ++j) {
            if (i == j)
                continue;
            else {
                s += table[group1[i] - 1][group1[j] - 1] + table[group1[j] - 1][group1[i] - 1];
                l += table[group2[i] - 1][group2[j] - 1] + table[group2[j] - 1][group2[i] - 1];
            }
        }
    }
    mn = min(mn, abs(s - l));
}

void recursive_comb(int n, int s, int l) {
    if (n == N) {
//        cout << "group: ";
//        for (int i = 0; i < N / 2; ++i) {
//            cout << group1[i] << ' ';
//        }
//        cout << "| ";
//        for (int i = 0; i < N / 2; ++i) {
//            cout << group2[i] << ' ';
//        }
//        cout << '\n';
        cal_points();
        return ;
    }
    if (s < N / 2) {
        group1[s] = n + 1;
        recursive_comb(n + 1, s + 1, l);
    }
    if (l < N / 2) {
        group2[l] = n + 1;
        recursive_comb(n + 1, s, l + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N * N; ++i) {
        cin >> table[i / N][i % N];
    }
    group1[0] = 1;
    recursive_comb(1, 1, 0);
    cout << mn;
}