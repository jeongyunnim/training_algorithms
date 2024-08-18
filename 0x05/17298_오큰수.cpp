//
// Created by 서정윤 on 2024. 8. 18..
//
#include <iostream>
#include <stack>

using namespace std;

#define MAX_ARG 1000001

int input[MAX_ARG];
int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    int n, val;
    stack<int> S;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> input[i];
    for (int i = n - 1; i >= 0; --i) {
        val = input[i];
        while (!S.empty() && S.top() <= val)
            S.pop();
        if (S.empty())
            input[i] = -1;
        else
            input[i] = S.top();
        S.push(val);
    }
    for (int i = 0; i < n; ++i) cout << input[i] << ' ';
    return 0;
}