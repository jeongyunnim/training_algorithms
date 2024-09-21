//
// Created by 서정윤 on 2024. 9. 21. 오후 7:59
//
#include <iostream>

using namespace std;
int arr[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, input;

    cin >> N;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i < 12; ++i) {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    for (int i = 0; i < N; ++i) {
        cin >> input;
        cout << arr[input] << '\n';
    }
}