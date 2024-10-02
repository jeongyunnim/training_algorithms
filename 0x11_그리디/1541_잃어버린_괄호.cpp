//
// Created by 서정윤 on 2024. 10. 1. 오후 7:09
//
#include <bits/stdc++.h>

using namespace std;
char input[51], len;

bool is_sign(char c) {
    return (c == '-' || c == '+');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    len = strlen(input);
    int plus = 0, minus = 0, current = 0;
    bool is_plus = true;
    for (int i = 0; i < len; ++i) {
        if (is_sign(input[i])) {
            if (is_plus)
                plus += current;
            else
                minus += current;

            current = 0;
            if (input[i] == '-')
                is_plus = false;
        } else {
            current *= 10;
            current += input[i] - '0';
        }
    }
    if (is_plus)
        plus += current;
    else
        minus += current;
    cout << plus - minus;
}