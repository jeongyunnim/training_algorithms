//
// Created by 서정윤 on 2024. 12. 22. 오후 4:12
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
bool arr[500001];
set<int> spot;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        if (arr[i]) {
            spot.insert(i);
        }
    }
    int pos = 1;
    for (int i = 0; i < M; ++i) {
        int op, n;
        cin >> op;
        if (op == 1) {
            cin >> n;
            if (arr[n]) {
                arr[n] = 0;
                spot.erase(n);
            } else {
                arr[n] = 1;
                spot.insert(n);
            }
        } else if (op == 2) {
            cin >> n;
//            cout << "moved " << pos << " -> " << (pos + n - 1) % N + 1 << '\n';
            pos = (pos + n - 1) % N + 1;
        } else {
            // print upper_bound
            if (spot.empty())
                cout << -1 << '\n';
            else {
                auto find_pos = spot.upper_bound(pos);
//                cout << "found: " << *find_pos << " cur: " << pos << '\n';
                if (arr[pos]) {
                    cout << "0\n";
                } else if (find_pos == spot.end()) {
                    cout << N - pos + *spot.begin() << '\n';
                } else {
                    cout << *find_pos - pos << '\n';
                }
            }
        }
    }
}