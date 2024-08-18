//
// Created by 서정윤 on 2024. 8. 19.
//
#include <iostream>
#include <queue>

using namespace std;
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    bool is_first = true;
    cin >> n;
    queue<int> Q;
    for (int i = 1; i <= n; i++) Q.push(i);

    while (Q.size() > 1) {
        if (is_first) {
            Q.pop();
            is_first = false;
        }
        else {
            Q.push(Q.front());
            Q.pop();
            is_first = true;
        }
    }
    cout << Q.front();
    return 0;
}