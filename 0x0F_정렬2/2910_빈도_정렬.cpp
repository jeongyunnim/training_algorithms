//
// Created by 서정윤 on 2024. 9. 17. 오후 7:20
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s_content {
    int count;
    int position;
} t_content;

bool compare(const pair<int, t_content> &a,const pair<int, t_content> &b) {
    if (a.second.count != b.second.count) {
        return a.second.count > b.second.count;
    }
    return a.second.position < b.second.position;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, t_content> M; // 값, 횟수, 출현한 인덱스
    int N, C, x;

    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        M[x].count += 1;
        if (M[x].position == 0)
            M[x].position = i + 1;
    }

    vector<pair<int, t_content> > V;
    V.assign(M.begin(), M.end());

    sort(V.begin(), V.end(), compare);

    for (auto el: V) {
        for (int i = 0; i < el.second.count; ++i) {
            cout << el.first << " ";
        }
    }
}