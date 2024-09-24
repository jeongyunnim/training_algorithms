//
// Created by 서정윤 on 2024. 9. 24. 오후 4:27
//
#include <iostream>

using namespace std;
int arr[1001];
int part[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, longest, mx = 0;
    cin >> N;
    part[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        longest = 0;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                longest = max(longest, part[j]);
            }
        }
        part[i] = longest + 1;
        mx = max(part[i], mx);
    }

    cout << mx;
}