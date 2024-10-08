//
// Created by 서정윤 on 2024. 10. 8. 오후 3:23
//
#include <bits/stdc++.h>

using namespace std;
char input[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    int len = strlen(input);
    int sum = 0;
    bool is_zero = false;
    for (int i = 0; i < len; ++i) {
        if (input[i] == '0') {
            is_zero = true;
        } else {
            sum += input[i] - '0';
        }
    }
    if (sum % 3 != 0 || !is_zero) {
        cout << -1;
    } else {
        sort(input, input + len, greater<int>());
        cout << input;
    }

}