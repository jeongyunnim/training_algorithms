//
// Created by 서정윤 on 2024. 9. 1..
//
#include <iostream>
#include <algorithm>

using namespace std;
int k;
int input[14];
int seq[6];
bool issued[14];

void recursive_compose(int n, int ptr) {
    if (n == 6) {
        for (int i = 0; i < 6; ++i)
            cout << seq[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = ptr; i < k; i++) {
        if (issued[i])
            continue ;
        seq[n] = input[i];
        issued[i] = true;
        recursive_compose(n + 1, i);
        issued[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> k;
        if (k == 0)
            return 0;
        for (int i = 0; i < k; ++i) {
            cin >> input[i];
        }
        sort(input, input + k);
        recursive_compose(0, 0);
        cout << '\n';
    }
}