//
// Created by 서정윤 on 2024. 10. 3. 오후 6:18
//
#include <bits/stdc++.h>

using namespace std;
char input[1000001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;
    int cnt = 1;
    bool is_zero = (input[0] == '0');
    for (int i = 1; input[i] != 0; ++i) {
        if (input[i] == '0') {
            if (!is_zero) {
                cnt += 1;
            }
            is_zero = true;
        } else {
            if (is_zero) {
                cnt+= 1;
            }
            is_zero = false;
        }
    }
    cout << cnt / 2;
}