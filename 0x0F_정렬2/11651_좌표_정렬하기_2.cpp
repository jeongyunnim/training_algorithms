//
// Created by 서정윤 on 2024. 9. 28. 오후 3:49
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int> > S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x, y;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        S.insert({y, x});
    }

    for (auto el: S) {
        cout << el.second << " " << el.first << '\n';
    }
}