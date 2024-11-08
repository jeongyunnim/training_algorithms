//
// Created by 서정윤 on 2024. 11. 8. 오후 3:44
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;

    cin >> input;
    size_t pos;
    pos = input.find('_');
    if (pos != string::npos) {
        for (string::iterator it = input.begin(); it != input.end();) {
            if (*it == '_' && it != input.begin() && it != input.end() - 1) {
                it = input.erase(it);
                if (*it == '_' || isupper(*it)) {
                    input = "Error!";
                    break ;
                }
                *it &= ~(0x20);
                ++it;
            } else if (islower(*it)) {
                ++it;
            } else {
                input = "Error!";
                break ;
            }
        }
    } else {
        for (string::iterator it = input.begin(); it != input.end(); ++it) {
            if (isupper(*it) && it != input.begin()) {
                *it |= 0x20;
                it = input.insert(it, '_');
            } else if (islower(*it)) {
                continue ;
            } else {
                input = "Error!";
                break;
            }
        }
    }
    cout << input;
}