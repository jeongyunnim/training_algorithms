//
// Created by 서정윤 on 2025. 1. 4. 오후 9:22
//
#include <bits/stdc++.h>

using namespace std;

unsigned long long ip[1001];
unsigned long long mask = -1;

void print_bit(unsigned long long x) {
    cout << x << " bit: ";
    for (int i = 63; i >= 0; --i) {
        if (x & (1 << i))
            cout << 1;
        else
            cout << 0;
        if (i % 8 == 0) cout << '.';
        else if (i % 4 == 0) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); ++j) {
            ip[i] |= stoi(&input[j]);
            while (input[j] != '\0' && input[j] != '.') {
                j += 1;
            }
            if (input[j] == '\0') break ;
            ip[i] <<= 8;
        }
    }
    for (int i = 1; i < N; ++i) {
        long long result = ip[0] ^ ip[i];
        int bit = 31;
        for (;bit >= 0; --bit) {
            if (!(mask & (1 << bit)) || result & (1 << bit)) break ;
        }
        mask &= (~((1L << (bit + 1)) - 1)); // int 형으로 계산되어 1을 32밀었을 때 overflow가 일어난다.
    }
    ip[0] &= mask;
    for (int i = 3; i >= 0; --i) {
        cout << ((ip[0] >> (8 * i)) & 0xFF);
        if (i != 0)
            cout << '.';
    }
    cout << '\n';
    for (int i = 3; i >= 0; --i) {
        cout << ((mask >> (8 * i)) & 0xFF);
        if (i != 0)
            cout << '.';
    }
}