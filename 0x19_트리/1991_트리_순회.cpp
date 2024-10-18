//
// Created by 서정윤 on 2024. 10. 18. 오후 5:29
//
#include <bits/stdc++.h>

using namespace std;

int lc[27];
int rc[27];

void pre(int cur) {
    char c = cur + 'A' - 1;
    cout << c;
    if (lc[cur]) pre(lc[cur]);
    if (rc[cur]) pre(rc[cur]);
}

void mid(int cur) {
    if (lc[cur]) mid(lc[cur]);
    char c = cur + 'A' - 1;
    cout << c;
    if (rc[cur]) mid(rc[cur]);
}

void pos(int cur) {
    if (lc[cur]) pos(lc[cur]);
    if (rc[cur]) pos(rc[cur]);
    char c = cur + 'A' - 1;
    cout << c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    cin >> N;
    char p, l, r;
    for (int i = 0; i < N; ++i) {
        cin >> p >> l >> r;
        if (l != '.') lc[p - 'A' + 1] = l - 'A' + 1;
        if (r != '.') rc[p - 'A' + 1] = r - 'A' + 1;
    }

    pre(1);
    cout << '\n';
    mid(1);
    cout << '\n';
    pos(1);
}