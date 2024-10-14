//
// Created by 서정윤 on 2024. 10. 14. 오후 4:26
//
#include <bits/stdc++.h>

using namespace std;
int N, M, x;
int input[100001];

//bool find_x(int r, int l, int target) {
//    int mid = (r + l) / 2;
//    if (mid < r)
//        return 0;
//    if (input[mid] == target)
//        return 1;
//    else if (input[mid] < target)
//        return find_x(mid + 1, l, target);
//    else
//        return find_x(r, mid - 1, target);
//}

bool find_x(int target) {
    int r = 0, l = N - 1;
    while (r <= l) {
        int mid = (r + l) / 2;
        if (input[mid] == target)
            return 1;
        else if (input[mid] < target) {
            r = mid + 1;
        }
        else {
            l = mid - 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    cin >> M;
    sort(input, input + N);
    for (int i = 0; i < M; ++i) {
        cin >> x;
        cout << find_x(x) << '\n';
    }
}
