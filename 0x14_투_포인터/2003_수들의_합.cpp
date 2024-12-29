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
    /*
     * arr의 요소가 항상 양수라는 조건 아래,
     * en과 st의 관계가 항상 `st <= en`을 만족한다.
     */
    while (st < N) {
        if (sum < M && en < N) { // sum이 M보다 작고 en이 N 밤위 이내일 때 확장
            sum += arr[en++];
        } else { // sum이 M 보다 큰 경우 st를 증가시켜 범위를 확장
            sum -= arr[st++];
        }
        if (sum == M) {
            cnt++;
        }
    }
    cout << cnt;
}