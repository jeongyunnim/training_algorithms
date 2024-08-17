//
// Created by 서정윤 on 8/16/24.
//
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    stack<char> braces;
    bool flag = true;

    while (getline(cin, input)) {
        flag = true;
        braces = stack<char>();

        if (input == ".")
            return 0;
        for (int i = 0 ; i < input.size(); i++) {
            char letter = input[i];
            if (letter == '(' || letter == '[') {
                braces.push(letter);
            }
            else if (letter == ')' || letter == ']') {
                if (braces.empty()) {
                    flag = false;
                    break ;
                }
                else if ((letter == ')' && braces.top() == '(') || (letter == ']' && braces.top() == '['))
                    braces.pop();
                else {
                    flag = false;
                    break ;
                }
            }
            else if (letter == '.')
                break ;
        }
        if (flag && braces.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
}