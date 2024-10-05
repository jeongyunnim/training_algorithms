//
// Created by 서정윤 on 2024. 10. 5. 오후 9:45
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    for (int i = 2; i <= N / i; i++) {
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
    if (N != 1)
        cout << N;
}