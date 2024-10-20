//
// Created by 서정윤 on 2024. 10. 5. 오후 3:13
//
#include <bits/stdc++.h>

using namespace std;
int N, M, C;

typedef struct s_info {
    int s;
    int e;
    int amount;
} info;

info vil[100001];
int limit[100001];
queue<pair<int, int> > Q;

bool compare(const info &lhs, const info &rhs) {
    if (lhs.e != rhs.e)
        return lhs.e < rhs.e;
    if (lhs.s != rhs.s)
        return lhs.s < rhs.s;
    return lhs.amount < rhs.amount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C >> M;

    for (int i = 0; i < M; ++i) {
        cin >> vil[i].s >> vil[i].e >> vil[i].amount;
    }

    sort(vil, vil + M, compare);

    int mx = 0;
    for (int i = 0; i < M; ++i) {
        int take, cap_max = 0;

        for (int j = vil[i].s; j < vil[i].e; ++j) {
            cap_max = max(cap_max, limit[j]);
        }

        if (cap_max >= C) continue ;
        else if (C - cap_max < vil[i].amount) {
            take = C - cap_max;
        } else {
            take = vil[i].amount;
        }
        mx += take;
        for (int j = vil[i].s; j < vil[i].e; ++j) {
            limit[j] += take;
        }
    }

    cout << mx;
}