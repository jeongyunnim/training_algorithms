//
// Created by 서정윤 on 2024. 12. 12. 오후 2:48
//
#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a_idx = 0;
    priority_queue<int, vector<int>, greater<int> > Q;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x != 0) {
            Q.push(x);
        } else {
            if (Q.empty())
                cout << "0\n";
            else {
                cout << Q.top() << '\n';
                Q.pop();
            }
        }
    }
}