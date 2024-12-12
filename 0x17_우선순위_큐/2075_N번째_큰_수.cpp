//
// Created by 서정윤 on 2024. 12. 12. 오후 5:24
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int> > Q;
    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (Q.size() < N)
                Q.push(x);
            else {
                if (Q.top() < x) {
                    Q.pop();
                    Q.push(x);
                }
            }
        }
    }
    cout << Q.top();
}