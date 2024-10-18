//
// Created by 서정윤 on 2024. 10. 18. 오후 7:35
//
#include <bits/stdc++.h>

using namespace std;
int N, P, M;
multiset<pair<int, int>> problems;
int problems_i[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int p, l;
    for (int i = 0; i < N; ++i) {
        cin >> p >> l;
        problems.insert({l, p});
        problems_i[p] = l;
    }
    cin >> M;
    string op;
    int num;
    for (int i = 0; i < M; ++i) {
        cin >> op;
        if (op[0] == 'a') {
            cin >> p >> l;
            problems.insert({l, p});
            problems_i[p] = l;
        } else if (op[0] == 'r') {
            cin >> num;
            if (problems.size() == 0) continue ;
            if (num == 1) {
                cout << prev(problems.end())->second << '\n';
            } else {
                cout << problems.begin()->second << '\n';
            }
        } else {
            cin >> num;
            problems.erase(problems.find({problems_i[num], num}));
        }

    }
}