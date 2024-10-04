//
// Created by 서정윤 on 2024. 10. 3. 오후 5:35
//
#include <bits/stdc++.h>

using namespace std;
int input[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    if (N == 1) {
        cout << input[0];
        return 0;
    }

    sort(input, input + N, greater<int>());
    int res = 0;
    int cnt_zero = 0;
    int i = 0;
    for (; i < N; ++i) {
//        cout << i << ": " << input[i] << '\n';
        if (input[i] > 0) {
            if (i < N - 1 && input[i + 1] > 1) {
//                cout << res << " += " << input[i] << " * " << input[i + 1] << '\n';
                res += input[i] * input[i + 1];
                i += 1;
            } else {
                res += input[i];
            }
        } else if (input[i] == 0) {
            cnt_zero += 1;
        } else {
            break ;
        }
    }
    for (int j = N - 1; j >= i; --j) {
        // input[i] < 0
        if (j - 1 >= i && input[j - 1] < 0) {
            res += input[j] * input[j - 1];
            j -= 1;
        } else if (cnt_zero == 0) {
            res += input[j];
        } else {
            continue ;
        }
    }
    cout << res;
}