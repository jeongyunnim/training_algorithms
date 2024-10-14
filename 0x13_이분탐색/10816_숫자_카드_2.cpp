//
// Created by 서정윤 on 2024. 10. 14. 오후 5:14
//
#include <bits/stdc++.h>

using namespace std;
int N, M, x;
int input[10000001];

int upper_index(int target) {
    int l = 0;
    int r = N;
    while (l < r) {
        int mid = (r + l) / 2;
        if (input[mid] > target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int lower_index(int target) {
    int l = 0;
    int r = N;
    while (l < r) {
        int mid = (r + l) / 2;
        if (input[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N);
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> x;
        cout << upper_index(x) - lower_index(x) << ' ';
    }

}