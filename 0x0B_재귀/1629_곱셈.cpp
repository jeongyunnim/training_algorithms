//
// Created by 서정윤 on 2024. 8. 27..
//
#include <iostream>

using namespace std;

int A, B, C;
long long recursive_multiple(int time) {
    if (time == 1)
        return A % C;

    long long res;
    res = recursive_multiple(time / 2);
    res = res * res % C;
    if (time % 2 == 1)
        return res * A % C;
    else
        return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << recursive_multiple(B);

    return 0;
}