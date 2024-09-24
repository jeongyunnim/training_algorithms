//
// Created by 서정윤 on 2024. 9. 24. 오후 3:39
//
#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x, mn, mx = INT32_MIN;

    cin >> N;
    arr[0] = 0;
    mn = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> x;
        arr[i] = arr[i - 1] + x;
        mx = max({mx, arr[i] - mn, arr[i]});
        mn = min(mn, arr[i]);
    }
//    for (int i = 1; i <= N; ++i) {
//        for (int j = i - 1; j >= 0; --j) {
//            mn = min(mn, arr[j]);
//        }
//        mx = max(mx, arr[i] - mn);
//    }
    cout << mx;
}