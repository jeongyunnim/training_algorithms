//
// Created by 서정윤 on 2024. 11. 28. 오후 3:14
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start, end_council, end_streaming;
    set<string> attended;
    set<string> exited;

    cin >> start >> end_council >> end_streaming;
    while (!cin.eof()) {
        string time, nickname;
        cin >> time >> nickname;
        if (time <= start) {
            attended.insert(nickname);
        } else if (end_council <= time && time <= end_streaming) {
            exited.insert(nickname);
        }
    }
    int cnt = 0;
    for (auto el : attended) {
        if (exited.find(el) != exited.end()) {
//            cout << el << '\n';
            cnt += 1;
        }
    }
    cout << cnt;
}