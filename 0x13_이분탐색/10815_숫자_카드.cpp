//
// Created by 서정윤 on 2024. 10. 16. 오후 6:00
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
int input[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N);
    cin >> M;
        int x;
    for (int i = 0; i < M; ++i) {
        cin >> x;
        if (binary_search(input, input + N, x))
            cout << "1 ";
        else
            cout << "0 ";
    }
}