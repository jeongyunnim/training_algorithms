//
// Created by 서정윤 on 2024. 10. 14. 오후 6:52
//
#include <bits/stdc++.h>

using namespace std;
int N;
int input[1000001];
int sorted[1000001];
int trimmed[1000001];
int offset = 1;

void trim() {

    trimmed[0] = sorted[0];
    for (int i = 1; i < N; ++i) {
        if (trimmed[offset - 1] != sorted[i]) {
            trimmed[offset] = sorted[i];
            offset += 1;
        }
    }
}

int find_x(int target) {
    int l = 0, r = offset - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (trimmed[m] == target)
            return m;
        else if (trimmed[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
        sorted[i] = input[i];
    }
    sort(sorted, sorted + N);

    trim();
//    for (int i = 0; i < offset; ++i) {
//        cout << trimmed[i] << " ";
//    }
//    cout << '\n';
    for (int i = 0; i < N; ++i) {
        cout << find_x(input[i]) << " ";
    }
}