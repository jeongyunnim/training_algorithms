//
// Created by 서정윤 on 2024. 11. 6. 오후 12:35
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> S;

    string input;
    int time = 0;
    while (1) {
        cin >> input;
        int cnt = 0;
        if (input[0] == '-')
            break ;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '{') {
                S.push('{');
            } else {
                if (S.empty()) {
                    cnt += 1;
                    S.push('{');
                } else {
                    S.pop();
                }
            }
        }
        while (!S.empty()) {
            S.pop();
            S.pop();
            cnt += 1;
        }
        cout << ++time << ". "<< cnt << '\n';
    }
}