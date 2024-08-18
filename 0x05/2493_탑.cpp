//
// Created by 서정윤 on 2024. 8. 18..
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_VAL 500001
int nums[MAX_VAL];


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<pair<int, int> > S;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        while (!S.empty() && S.top().first <= nums[i])
            S.pop();
        if (S.empty() || S.top().first < nums[i]) {
            cout << "0 ";
        } else if (S.top().first > nums[i]) {
            cout << S.top().second << " ";
        }
        S.push({nums[i], i + 1});
    }
    return 0;
}