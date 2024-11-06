//
// Created by 서정윤 on 2024. 11. 5. 오후 12:52
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    int added = 0;
    int sz = input.size();

    if (sz == 1) {
        cout << 1;
        return 0;
    }
    int st = 0;
    while (st < sz) {
        int en = sz - 1;
        while (st < sz && input[st] != input[en]) {
            st += 1;
        }
        bool is_ok = true;
        for (int s = st; s < en; ++s, --en) {
            if (input[s] != input[en]) {
                is_ok = false;
                break ;
            }
        }
        if (is_ok) {
            cout << st + sz;
            return 0;
        }
        st += 1;
    }
}