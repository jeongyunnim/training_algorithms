//
// Created by 서정윤 on 2024. 10. 17. 오후 6:10
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, K;

    cin >> T;
    while (T--) {
        multiset<int> S;
        cin >> K;
        for (int i = 0; i < K; ++i) {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'D') {
                if (S.empty()) continue ;
                if (num == 1) {
                    // 최댓값 삭제
                    S.erase(prev(S.end()));
                } else {
                    // 최솟값 삭제
                    S.erase(S.begin());
                }
            } else {
                S.insert(num);
            }
        }
        if (S.empty())
            cout << "EMPTY\n";
        else
            cout << *S.rbegin() << " " << *S.begin() << '\n';
    }
}