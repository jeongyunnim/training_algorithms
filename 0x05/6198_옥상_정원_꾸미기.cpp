//
// Created by 서정윤 on 2024. 8. 18..
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_VAL 80001
int nums[MAX_VAL];


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count = 0;
    long long sum = 0; // sum의 범위는 21억이 넘을 수도 있다.
    stack<pair<int, long long> > S;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = n - 1; i >= 0; --i) {
        count = 0;
        while (!S.empty() && S.top().first < nums[i]) {
            count += S.top().second + 1;
            S.pop();
        }

        S.push({nums[i], count});
        sum += count;
    }
    cout << sum;
    return 0;
}