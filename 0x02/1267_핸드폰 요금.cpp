//
// Created by 서정윤 on 8/17/24.
//
#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int input;
    int n;
    int y = 0, m = 0;

    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> input;
        y += (input / 30) + 1;
        m += (input / 60) + 1;
    }
    y *= 10;
    m *= 15;
    if (y == m)
        cout << "Y M " << y;
    else if (y < m)
        cout << "Y " << y;
    else
        cout << "M " << m;
    return 0;
}