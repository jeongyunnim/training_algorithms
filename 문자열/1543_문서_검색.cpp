//
// Created by 서정윤 on 2024. 11. 7. 오후 5:33
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string src, dest;
    getline(cin, src);
    getline(cin, dest);

    int cnt = 0;
    if (src.size() < dest.size()) {
        cout << 0;
        return 0;
    }
    size_t pos = src.find(dest);
    while (pos != string::npos) {
//        cout << src.substr(pos, dest.size()) << '\n';
        pos = src.find(dest, pos + dest.size());
        cnt += 1;
    }

    cout << cnt;
}