//
// Created by 서정윤 on 2024. 9. 17. 오전 1:58
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    int input[1000001];

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N, less<int>());
    for (int i = 0; i < N; ++i) {
        cout << input[i] << '\n';
    }
}