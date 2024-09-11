//
// Created by 서정윤 on 2024. 9. 11. 오후 6:17
//
#include <iostream>
using namespace std;

int N, mx = INT32_MIN, mn = INT32_MAX;
int input[12];
int operators[4];
int combination[10];
enum {PL, MI, MU, DI};

int cal() {
    int res = input[0];
    for (int i = 1; i < N; ++i) {
        if (combination[i - 1] == PL)
            res += input[i];
        else if (combination[i - 1] == MI)
            res -= input[i];
        else if (combination[i - 1] == MU)
            res *= input[i];
        else
            res /= input[i];
    }
    return res;
}

void recursive_comb(int n) {
    int res;
    if (n == N - 1) {
        res = cal();
//        for (int i = 0; i < N - 1; ++i)
//            cout << combination[i] << ' ';
//        cout << ": " << res << '\n';
        mx = max(mx, res);
        mn = min(mn, res);
        return ;
    }
    for (int i = 0; i < 4; ++i) {
        if (operators[i] == 0) continue ;
        combination[n] = i;
        operators[i] -= 1;
        recursive_comb(n + 1);
        combination[n] = i;
        operators[i] += 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }
    recursive_comb(0);
    cout << mx << '\n' << mn;
}