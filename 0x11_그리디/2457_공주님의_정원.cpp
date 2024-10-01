//
// Created by 서정윤 on 2024. 9. 30. 오후 7:59
//
#include <bits/stdc++.h>

using namespace std;

typedef struct s_day {
    int m;
    int d;
} day;

int N;
vector<pair<day, day> > V;

bool compare(const pair<day, day> &lhs, const pair<day, day> &rhs) {
    if (lhs.second.m != rhs.second.m)
        return lhs.second.m < rhs.second.m;
    else if (lhs.second.d != rhs.second.d)
        return lhs.second.d < rhs.second.d;
    else if (lhs.first.m != rhs.first.m)
        return lhs.first.m < rhs.first.m;
    else if (lhs.first.d != rhs.first.d)
        return lhs.first.d < rhs.first.d;
    return false;
}

int find_first_day() {
    int ret = -1;
    for (int i = 0; i < N; ++i) {
        if (V[i].first.m > 3 || (V[i].first.m == 3 && V[i].first.d > 1))
            continue ;
        ret = i;
    }
    return ret;
}

int find_next_day(int current) {
    // 현재 값의 마지막 날까지 선택할 수 있는 값 중 가장 나중의 값. current 이후 부터 생각한다.
    int ret = -1;

    for (int i = current + 1; i < N; ++i) {
        // 비교하려는 꽃을 선택할 수 없으면 continue;
        if (V[i].first.m > V[current].second.m || (V[i].first.m == V[current].second.m && V[i].first.d > V[current].second.d))
            continue ;
        ret = i;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    day s, l;
    for (int i = 0; i < N; ++i) {
        cin >> s.m >> s.d >> l.m >> l.d;
        V.push_back({{s.m, s.d}, {l.m, l.d}});
    }
    sort(V.begin(), V.end(), compare);

    int next = find_first_day();
    if (next == -1) {
        cout << 0;
        return 0;
    } else if (V[next].second.m > 11) {
        cout << 1;
        return 0;
    }

    int cnt = 1;
    while (true) {
        next = find_next_day(next);
        cnt += 1;
        if (next == -1) {
            cout << 0;
            return 0;
        }
        if (V[next].second.m > 11)
            break ;
    }
    cout << cnt;
}