//
// Created by 서정윤 on 2025. 1. 25. 오전 10:15
//
#include <bits/stdc++.h>

using namespace std;
list<char> palindrome;
int alpha[26];
bool is_odd = false;
char odd;

bool check_validation() {
    for (int i = 0; i < 26; ++i) {
        if (!(alpha[i] % 2)) continue ;
        if (!is_odd) {
            odd = i + 'A';
            is_odd = true;
        }
        else
            return false;
    }
    return true;
}

int main() {
    string input;

    cin >> input;
    for (int i = 0; i < input.size();++i) {
        alpha[input[i] - 'A'] += 1;
    }
    if (!check_validation()) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string ans;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < alpha[i] / 2; ++j)
            ans.push_back(i + 'A');
    }
    cout << ans;
    if (is_odd)
        cout << odd;
    for (string::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it;
    }
}