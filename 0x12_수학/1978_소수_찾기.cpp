//
// Created by 서정윤 on 2024. 10. 5. 오후 9:06
//
#include <bits/stdc++.h>

using namespace std;
/*
 * 4
 * 1 3 5 7
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    int input[101], cnt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < N; ++i) {
        bool is_prime = true;
        if (input[i] <= 1) continue ;
        for (int j = 2; j * j <= input[i]; ++j) {
            if (input[i] % j == 0) {
                is_prime = false;
                break ;
            }
        }
        cnt += is_prime;
    }
    cout << cnt;
}