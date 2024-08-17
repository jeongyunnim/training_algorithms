//
// Created by 서정윤 on 2024. 8. 17.
//

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

char op[400001]; // 100,000(operator max value) * 2(pop, push) * 2('\n')
int offset;

void concat(char c) {
    op[offset++] = c;
    op[offset++] = '\n';
}

int main() {

    int n, x, index = 0, count = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (index <= x) {
            for (; index < x;) {
                S.push(++index);
                concat('+');
            }
            concat('-');
            S.pop();
        } else if (S.empty() || S.top() != x) {
            cout << "NO";
            return 0;
        } else {
            concat('-');
            S.pop();
        }
    }
    cout << op;
    return (0);
}
