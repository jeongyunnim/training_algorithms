//
// Created by 서정윤 on 2024. 11. 15. 오후 4:08
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    unordered_map<string, string> UM;

    cin >> N >> M;
    string site, pw;
    for (int i = 0; i < N; ++i) {
        cin >> site >> pw;
        UM[site] = pw;
    }
    for (int i = 0; i < M; ++i) {
        cin >> site;
        cout << UM[site] << '\n';
    }
}