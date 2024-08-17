//
// Created by 서정윤 on 8/16/24.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {

    int count;
    string op;
    int input_num;
    queue<int> q;

    cin >> count;
    while (count--) {
        cin >> op;
        if (op == "push") {
            cin >> input_num;
            q.push(input_num);
        }
        else if (op == "pop") {
            if (q.empty())
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (op == "size") {
            cout << q.size() << "\n";
        }
        else if (op == "empty") {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (op == "front") {
            if (q.empty())
                cout << -1 << "\n";
            else
               cout << q.front() << "\n";
        }
        else if (op == "back") {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }

    return 0;
}