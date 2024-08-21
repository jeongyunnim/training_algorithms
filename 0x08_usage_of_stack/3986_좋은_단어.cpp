//
// Created by 서정윤 on 2024. 8. 20..
//
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char input[100001];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    int N, count = 0, len;

    cin >> N;

    while (N--) {
        cin >> input;
        S = stack<char>();
        len = strlen(input);
        if (len % 2)
            continue ;
        for (int i = 0; i < len; i++) {
            if (!S.empty() && S.top() == input[i])
                S.pop();
            else
                S.push(input[i]);
        }
        if (!S.empty())
            continue ;
        else
            count += 1;
    }
    cout << count;
    return 0;
}