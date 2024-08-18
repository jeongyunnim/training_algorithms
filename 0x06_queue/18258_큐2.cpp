//
// Created by 서정윤 on 2024. 8. 19.
//
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    char op[6];
    queue<int> Q;
    cin >> n;

    while (n--) {
        cin >> op;
        if (!strcmp(op, "push")) {
            cin >> x;
            Q.push(x);
        }
        else if (!strcmp(op, "pop")) {
            if (Q.empty())
                cout << -1 << '\n';
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if (!strcmp(op, "size")) {
            cout << Q.size() << '\n';
        }
        else if (!strcmp(op, "empty")) {
            if (Q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';

        }
        else if (!strcmp(op, "front")) {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.front() << '\n';

        }
        else if (!strcmp(op, "back")) {
            if (Q.empty())
                cout << -1 << '\n';
            else
                cout << Q.back() << '\n';
        }
    }
    return 0;
}