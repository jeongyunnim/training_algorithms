//
// Created by 서정윤 on 2024. 10. 4. 오후 4:29
//
#include <bits/stdc++.h>

using namespace std;
int input[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    int pre;
    int cnt = 0;
    for (int i = N - 2; i >= 0; --i) {
        pre = input[i + 1];
        if (pre <= input[i]) {
            cnt += input[i] - pre + 1;
            input[i] = pre - 1;
        }
    }
    cout << cnt;
}