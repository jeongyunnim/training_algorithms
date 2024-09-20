//
// Created by 서정윤 on 2024. 9. 18. 오후 3:38
//
#include <iostream>
#include <algorithm>

using namespace std;

int N, A, B, x;
int input_a[20001];
int input_b[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        for (int j = 0; j < A; ++j) {
            cin >> input_a[j];
        }
        for (int j = 0; j < B; ++j) {
            cin >> input_b[j];
        }
        sort(input_a, input_a + A, greater<int>());
        sort(input_b, input_b + B, greater<int>());
        int cnt = 0;
        for (int j = 0, k = 0; j < A; ++j) {
            while (k < B && input_a[j] <= input_b[k])
                k++;
            cnt += B - k;
            continue ;
        }
        cout << cnt << '\n';
    }


}