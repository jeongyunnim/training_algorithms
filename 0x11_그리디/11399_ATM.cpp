//
// Created by 서정윤 on 2024. 9. 30. 오후 7:48
//
#include <bits/stdc++.h>

using namespace std;

int N;
int input[1001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += input[i] * (N - i);
    }
    cout << ans;
}