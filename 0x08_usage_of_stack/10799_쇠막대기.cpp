//
// Created by 서정윤 on 2024. 8. 20..
//
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
char input[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<char, int> > S;
    int laser_count, sum = 0;
    bool laser = false;

    cin >> input;
    char* p = input;

    while (*p != '\0') {
        if (*p == '(') {
            S.push({*p, 0});
            laser = true;
        } else {
            if (!S.empty() && laser) {
                S.pop();
                if (!S.empty())
                    S.top().second += 1;
                laser = false;
            } else {
                laser_count = S.top().second;
                sum += laser_count + 1;
                S.pop();
                if (!S.empty())
                    S.top().second += laser_count;
            }
        }
        p += 1;
    }
    cout << sum;
    return (0);
}