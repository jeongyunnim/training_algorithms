//
// Created by 서정윤 on 8/17/24.
//
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long a, b;
    unsigned long long mx, mn;
    cin >> a >> b;
    if (a == b) {
        cout << "0"; return 0;
    }
    mx = max(a,b);
    mn = min(a, b);
    cout << mx - mn - 1<< '\n';
    for (mn += 1; mn < mx ; mn++)
        cout << mn << '\n';
    return 0;
}