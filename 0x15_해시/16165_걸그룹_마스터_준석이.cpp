//
// Created by 서정윤 on 2024. 11. 28. 오후 1:31
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> groups;
    int N, M;
    cin >> N >> M;
    string group, name;
    for (int i = 0; i < N; ++i) {
        int member_cnt;
        cin >> group >> member_cnt;
        for (int j = 0; j < member_cnt; ++j) {
            cin >> name;
            groups[name] = group;
        }
    }
    bool q_type;
    for (int i = 0; i < M; ++i) {
        cin >> name >> q_type;
        if (q_type) {
            cout << groups[name] << '\n';
        } else {
            for (auto el : groups) {
                if (el.second == name) {
                    cout << el.first << '\n';
                }
            }
        }
    }
}