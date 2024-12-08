//
// Created by 서정윤 on 2024. 12. 7. 오전 12:59
//
#include <bits/stdc++.h>

using namespace std;
string input, bomb;
int num_bit_flag, char_bit_flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input >> bomb;

    stack<char> S;
    for (int i = 0; i < input.size(); ++i) {
        char c = input[i];
        string::reverse_iterator it = bomb.rbegin();
        S.push(c);
        if (c == *it) {
            bool is_match = false;
            while (!S.empty()) {
                if (S.top() == *it) {
                    S.pop();
                    ++it;
                    if (it == bomb.rend()) {
                        is_match = true;
                        break ;
                    }
                } else {
                    break ;
                }
            }
            while (!is_match && it != bomb.rbegin()) {
                --it;
                S.push(*it);
            }
        }
    }
    string ans;
    while (!S.empty()) {
        ans.push_back(S.top());
        S.pop();
    }
    std::reverse(ans.begin(), ans.end());
    if (ans.empty())
        cout << "FRULA";
    else
        cout << ans;
}