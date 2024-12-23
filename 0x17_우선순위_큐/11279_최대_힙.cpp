//
// Created by 서정윤 on 2024. 12. 23. 오후 11:00
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> Q;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            if (Q.empty())
                cout << "0\n";
            else {
                cout << Q.top() << '\n';
                Q.pop();
            }
        } else {
            Q.push(x);
        }
    }
}