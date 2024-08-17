//
// Created by 서정윤 on 8/16/24.
//

#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

int const MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}
void pop_back() {
    tail--;
}
int front() {
    return dat[head];
}
int back() {
    return dat[tail - 1];
}
int size() {
    return tail - head;
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string op;
    int count;
    int x;

    cin >> count;
    while (count--) {
        cin >> op;
        if (op == "push_front") {
            cin >> x;
            push_front(x);
        }
        else if (op == "push_back") {
            cin >> x;
            push_back(x);
        }
        else if (op == "pop_front") {
            if (size() == 0)
                cout << -1 << "\n";
            else {
                cout << front() << "\n";
                pop_front();
            }
        }
        else if (op == "pop_back") {
            if (size() == 0)
                cout << -1 << "\n";
            else {
                cout << back() << "\n";
                pop_back();
            }
        }
        else if (op == "size") {
            cout << size() << "\n";

        }
        else if (op == "empty") {
            if (size() == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (op == "front") {
            if (size() == 0)
                cout << -1 << "\n";
            else {
                cout << front() << "\n";
            }
        }
        else if (op == "back") {
            if (size() == 0)
                cout << -1 << "\n";
            else {
                cout << back() << "\n";
            }
        }
    }
    return 0;
}