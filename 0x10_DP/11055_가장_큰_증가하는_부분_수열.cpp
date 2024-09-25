//
// Created by 서정윤 on 2024. 9. 24. 오후 4:27
//
#include <iostream>

using namespace std;
int arr[1001];
int part[1001]; // 각 index를 가장 큰 수로 갖는 수열의 총합.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, mx = 0, biggest;
    cin >> N;
    part[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        biggest = 0;
        for (int j = 0; j < i; ++j) {
            // 자신보다 작은 수를 비교하면 그 중 가장 큰 수를 선택하여 더한다.
            if (arr[j] < arr[i]) {
                biggest = max(biggest, part[j]);
            }
        }
        part[i] = biggest + arr[i];
        mx = max(mx, part[i]);
    }
    cout << mx;
}