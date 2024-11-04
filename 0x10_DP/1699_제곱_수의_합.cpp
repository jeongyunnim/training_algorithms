//
// Created by 서정윤 on 2024. 11. 4. 오후 2:16
//
#include <bits/stdc++.h>

using namespace std;
int input[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    input[0] = 0;
    input[1] = 1;
    int cur_mx = 1;
    for (int i = 2; i <= N; ++i) {
        input[i] = 0x7fffffff;
        if ((cur_mx + 1) <= i / (cur_mx + 1))
            cur_mx += 1;
        for (int k = cur_mx; k > 0; --k) {
            input[i] = min(input[i], input[i - (k * k)]);
        }
        input[i] += 1;
    }
    cout << input[N];
}