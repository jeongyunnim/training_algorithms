//
// Created by 서정윤 on 8/16/24.
//
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

char input[51];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    stack<char> braces;
    bool flag = true;

    cin >> N;
    while (N--) {
        flag = true;
        braces = stack<char>();
        cin >> input;
        for (int i = 0 ; i < strlen(input); i++) {
            char letter = input[i];
            if (letter == '(') {
                braces.push(letter);
            }
            else if (letter == ')') {
                if (braces.empty()) {
                    flag = false;
                    break ;
                }
                else if ((letter == ')' && braces.top() == '('))
                    braces.pop();
                else {
                    flag = false;
                    break ;
                }
            }
        }
        if (flag && braces.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}