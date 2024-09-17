//
// Created by 서정윤 on 2024. 9. 17. 오후 1:13
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

string input[51];
int N;

bool compare(string &lhs, string &rhs) {
    if (lhs.size() != rhs.size())
        return lhs.size() < rhs.size();
    int r = 0, l = 0;

    for (int i = 0; i < lhs.size(); ++i) {
        if (isdigit(lhs[i]))
            l += lhs[i] - '0';
    }
    for (int i = 0; i < rhs.size(); ++i) {
        if (isdigit(rhs[i]))
            r += rhs[i] - '0';
    }
    if (r == l) {
        return (strcmp(lhs.c_str(), rhs.c_str()) < 0);
    } else {
        return l < r;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }

    sort(input, input + N, compare);
    for (int i = 0; i < N; ++i) {
        cout << input[i] << '\n';
    }
}