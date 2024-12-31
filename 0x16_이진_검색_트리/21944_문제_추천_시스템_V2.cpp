//
// Created by 서정윤 on 2024. 12. 30. 오전 8:52
//
#include <bits/stdc++.h>

using namespace std;
set<pair<int, int> > S_group[101];
set<int> S_level[101];
map<int, pair<int, int> > p_info;

void add_problem(int p, int l, int g) {
    S_group[g].insert({l, p});
    S_level[l].insert(p);
    p_info[p] = {l, g};
}

void erase_problem(int p, int l, int g) {
    S_group[g].erase({l, p});
    S_level[l].erase(p);
    p_info.erase(p);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, P;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int p, l, g;
        cin >> p >> l >> g;
        add_problem(p, l, g);
    }
    cin >> P;
    for (int i = 0; i < P; ++i) {
        string op;
        cin >> op;
        if (op == "recommend") {
            int g, x;
            cin >> g >> x;
            if (x == -1) {
                cout << S_group[g].begin()->second << '\n';
            } else {
                cout << prev(S_group[g].end())->second << '\n';
            }
        } else if (op == "recommend2") {
            int x;
            cin >> x;
            if (x == -1) {
                for (int l = 1; l <= 100; ++l) {
                    if (S_level[l].empty()) continue ;
                    cout << *S_level[l].begin() << '\n';
                    break ;
                }
            } else {
                for (int l = 100; l > 0; --l) {
                    if (S_level[l].empty()) continue ;
                    cout << *prev(S_level[l].end()) << '\n';
                    break ;
                }
            }
        } else if (op == "recommend3") {
            int x, l;
            bool print_flag = false;
            cin >> x >> l;
            if (x == -1) {
                for (int idx = l - 1; idx > 0; --idx) {
                    if (S_level[idx].empty()) continue ;
                    cout << *(S_level[idx].rbegin()) << '\n'; // 가장 큰 수 중 "가장 큰 번호"
                    print_flag = true;
                    break ;
                }
            } else {
                for (; l <= 100; ++l) {
                    if (S_level[l].empty()) continue ;
                    cout << *S_level[l].begin() << '\n'; // 가장 작은 수 중 "가장 작은 번호"
                    print_flag = true;
                    break ;
                }
            }
            if (!print_flag)
                cout << "-1\n";
        } else if (op == "add") {
            int p, l, g;
            cin >> p >> l >> g;
            add_problem(p, l, g);
        } else {
            int p, l, g;
            cin >> p;
            tie(l, g) = p_info[p];
            erase_problem(p, l, g);
        }
    }
}