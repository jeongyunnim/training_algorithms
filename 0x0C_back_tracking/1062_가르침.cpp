//
// Created by 서정윤 on 2024. 11. 4. 오후 7:34
//
#include <bits/stdc++.h>

using namespace std;
int string_bits[51];
int alpha_flag;
int N, K, cnt;

void print_bit(int bit) {
    cout << bit << ": ";
    for (int k = 31; k >= 0; --k) {
        if (bit & (1 << k))
            cout << "1";
        else
            cout << "0";
        bit &= ~(1 << k);
        if (k % 4 == 0) cout << " ";
    }
    cout << '\n';
}

void solve(int n, int pre) {
    if (n == K) {
        int cur = 0;
        for (int i = 0; i < N; ++i) {
            if ((string_bits[i] & alpha_flag) == string_bits[i])
                cur += 1;
        }
        cnt = max(cnt, cur);
        return ;
    }

    for (int i = pre + 1; i < 26; ++i) {
        if ((1 << i) & alpha_flag) continue ;
        alpha_flag |= (1 << i);
        solve(n + 1, i);
        alpha_flag &= ~(1 << i);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        for (auto c : input) {
            string_bits[i] |= (1 << (c - 'a'));
        }
    }
    if (K < 5) {
        cout << 0;
        return 0;
    }
    alpha_flag |= (1 << ('a' - 'a'));
    alpha_flag |= (1 << ('n' - 'a'));
    alpha_flag |= (1 << ('t' - 'a'));
    alpha_flag |= (1 << ('i' - 'a'));
    alpha_flag |= (1 << ('c' - 'a'));
    solve(5, 0);
    cout << cnt;
}