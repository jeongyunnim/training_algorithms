//
// Created by 서정윤 on 2024. 8. 21..
//
#include <iostream>
#include <stack>

using namespace std;

char input[31];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    char *p;
    int val = 1, sum = 0;
    char flag = 0;
    cin >> input;
    p = input;
    while (*p != '\0') {
        if (*p == '(' || *p == '[') {
            S.push(*p);
            if (*p == '(') {
                flag = 1;
                val *= 2;
            }
            else {
                flag = 2;
                val *= 3;
            }
        } else {
            if (S.empty()){
                sum = 0;
                break ;
            }
            if (*p == ')') {
                if (!S.empty() && S.top() != '(') {
                    sum = 0;
                    break ;
                }
                if (flag == 1) {
                    sum += val;
                }
                S.pop();
                val /= 2;
            } else {
                if (!S.empty() && S.top() != '[') {
                    sum = 0;
                    break ;
                }
                if (flag == 2) {
                    sum += val;
                }
                S.pop();
                val /= 3;
            }
            flag = 0;
        }
        p += 1;
    }
    if (!S.empty())
        sum = 0;
    cout<< sum << '\n';
    return 0;
}