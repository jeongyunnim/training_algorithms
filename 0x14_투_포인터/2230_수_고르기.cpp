//
// Created by 서정윤 on 2024. 10. 16. 오후 7:07
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
int A[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A, A + N);
    int st = 0, en = 1, ans = numeric_limits<int>::max();
    while (en != N && st != N - 1) {
        int subtract = A[en] - A[st];
        if (subtract == M) {
            ans = M;
            break ;
        }
        else if (subtract < M) {
            en++;
        } else {
            ans = min(ans, subtract);
            st++;
        }
    }
    cout << ans;
}