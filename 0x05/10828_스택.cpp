//
// Created by 서정윤 on 8/16/24.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int count;
    int input_num;
    int pos = 0;
    vector<int> my_stack;
    string op;

    cin >> count;
    while (count--) {
        cin >> op;
        if (op == "push") {
            cin >> input_num;
            my_stack.push_back(input_num);
            pos += 1;
        }
        else if (op == "top") {
            if (pos == 0)
                cout << -1 << "\n";
            else
                cout << my_stack[pos - 1] << "\n";
        }
        else if (op == "size")
            cout << pos << "\n";
        else if (op == "empty") {
            if (pos == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (op == "pop") {
            if (pos == 0)
                cout << -1 << "\n";
            else {
                --pos;
                cout << my_stack[pos] << "\n";
                my_stack.pop_back();
            }
        }
    }

    return 0;
}