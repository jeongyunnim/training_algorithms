//
// Created by 서정윤 on 2024. 9. 21. 오후 2:50
//
#include <iostream>
#include <algorithm>
/**
 * 1. 테이블 정의하기
 * 2. 점화식 찾기
 * 3. 초기값 정의하기
 */
using namespace std;

int N;
int arr[1000001];

void fill_arr() {
    arr[1] = 0;
    for (int i = 2; i <= N; ++i) {
        int divide_2 = 0x7f7f7f7f;
        int divide_3 = 0x7f7f7f7f;
        if (i % 2 == 0) {
            divide_2 = arr[i / 2];
        }
        if (i % 3 == 0) {
            divide_3 = arr[i / 3];
        }
        arr[i] = min({divide_2, divide_3, arr[i - 1]}) + 1;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill_arr();
    cout << arr[N];
}