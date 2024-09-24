//
// Created by 서정윤 on 2024. 9. 23. 오후 6:04
//
#include <iostream>

using namespace std;
int ways[1001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    ways[1] = 1;
    ways[2] = 3;
    for (int i = 3; i <= N; ++i) {
        ways[i] = (ways[i - 1] + 2 * ways[i - 2]) % 10007;
    }
    cout << ways[N];
}