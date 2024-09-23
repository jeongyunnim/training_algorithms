//
// Created by 서정윤 on 2024. 9. 23. 오후 6:14
//
#include <iostream>

using namespace std;
int res[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, start, end, x;

    cin >> N >> M;

    res[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        res[i] = res[i - 1] + x;
    }


    for (int i = 0; i < M; ++i) {
        cin >> start >> end;
        cout << res[end] - res[start - 1] << "\n";
    }
}