//
// Created by 서정윤 on 2024. 12. 26. 오후 10:23
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        priority_queue<long long, vector<long long>, greater<long long> > Q;

        for (int i = 0; i < N; ++i) {
            long long x;
            cin >> x;
            Q.push(x);
        }
        long long sum = 0;
        while (Q.size() > 1) {
            long long first_min = Q.top();
            Q.pop();
            long long second_min = Q.top();
            Q.pop();
            long long merge_cost = first_min + second_min;
            Q.push(merge_cost);
            sum += merge_cost;
        }
        cout << sum << '\n';
    }
}