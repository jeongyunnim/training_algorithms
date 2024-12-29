//
// Created by 서정윤 on 2024. 12. 29. 오후 10:46
//
#include <bits/stdc++.h>

using namespace std;
int arr[10001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int cnt = 0, sum = 0, st = 0, en = 0;
    while (st < N) {
        if (sum < M && en < N) { // TODO: st가 en을 넘어가지 않는지 검증해야 한다.
            sum += arr[en++];
        } else {
            sum -= arr[st++];
        }
        if (sum == M) {
            cnt++;
        }
    }
    cout << cnt;
}