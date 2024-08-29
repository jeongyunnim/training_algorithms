//
// Created by 서정윤 on 2024. 8. 28..
//
#include <iostream>

using namespace std;

int N, r, c;

int recursive_search(int n, int x, int y) {
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (x < half && y < half)
        return recursive_search(n - 1, x, y);
    else if (x >= half && y < half)
        return half * half + recursive_search(n - 1, x - half, y);
    else if (x < half && y >= half)
        return 2 * half * half + recursive_search(n - 1, x, y - half);
    else
        return 3 * half * half + recursive_search(n - 1, x - half, y - half);
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;

    cout << recursive_search(N, c, r);
    return 0;
}