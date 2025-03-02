//
// Created by 서정윤 on 2025. 3. 2. 오후 2:59
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    stack<char> S;
    bool meet_A = false;

    cin >> input;
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];

        if (c == 'P') {
            if (meet_A) {
                if (S.size() < 2 || S.top() != 'P')
                    break ;
                S.pop();
                if (S.top() != 'P')
                    break ;
            } else {
                S.push(c);
            }
            meet_A = false;
        } else {
            if (meet_A)
                break ;
            meet_A = true;
        }
    }
    if (S.size() != 1 || S.top() != 'P' || meet_A)
        cout << "NP";
    else
        cout << "PPAP";
}