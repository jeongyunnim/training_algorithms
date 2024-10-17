//
// Created by 서정윤 on 2024. 10. 17. 오후 6:31
//
#include <bits/stdc++.h>

using namespace std;
int N, K;
pair<int, int> jewel[300001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    map<int ,int> M;
    for (int i = 0; i < N; ++i) {
        cin >> jewel[i].second >> jewel[i].first;
    }
    sort(jewel, jewel + N, greater<pair<int, int> >());
    multiset<int> cap; // 중복된 가방 값이 들어올 수 있음
    int wei, val;
    for (int i = 0; i < K; ++i) {
        cin >> wei;
        cap.insert(wei);
    }
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        tie(val, wei) = jewel[i];
        auto it = cap.lower_bound(wei);
        if (it == cap.end()) continue ;
        sum += val;
        cap.erase(it);
    }
    cout << sum;
}