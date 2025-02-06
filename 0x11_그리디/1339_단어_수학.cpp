//
// Created by 서정윤 on 2025. 2. 6. 오후 5:23
//
#include <bits/stdc++.h>

using namespace std;
int alpha[26];

int get_pos(int n) {
    int ret = 1;
    for (; n > 1; --n) {
        ret *= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        int len = input.size() - 1;
        for (int j = 0; j <= len; ++j) {
            alpha[input[j] - 'A'] += get_pos(len - j + 1);
        }
    }
    vector<int> V;
    for (int i = 0; i < 26; ++i) {
        if (!alpha[i]) continue ;
        V.push_back(alpha[i]);
    }
    sort(V.begin(), V.end());
    int ans = 0, weigh = 9;
    for (auto it = V.rbegin(); it != V.rend(); ++it) {
        ans += *it * weigh--;
    }
    cout << ans;
}