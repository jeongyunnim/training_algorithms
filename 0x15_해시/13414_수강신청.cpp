//
// Created by 서정윤 on 2024. 11. 15. 오후 3:18
//
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, int> lhs, pair<string, int> rhs) {
    if (lhs.second != rhs.second)
        return lhs.second < rhs.second;
    return lhs.first < rhs.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> requests;
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        string input;
        cin >> input;
        requests[input] = i;
    }
    vector<pair<string, int> > ans(requests.begin(), requests.end());
    sort(ans.begin(), ans.end(), compare);
    int cnt = 0;
    for (auto it = ans.begin(); it != ans.end(); ++it) {
        cout << it->first << '\n';
        if (++cnt == N)
            break ;
    }
}