//
// Created by 서정윤 on 2024. 8. 28..
//
#include <iostream>
#include <vector>

using namespace std;
vector<string> ans;

int K;

void recursive_sort(int src, int des, int n) {
    if (n == 1) {
        ans.push_back(to_string(src) + " " + to_string(des) + '\n');
        return ;
    }
    recursive_sort(src, 6 - src - des, n - 1);
    ans.push_back(to_string(src) + " " + to_string(des) + '\n');
    recursive_sort(6 - src - des, des, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    recursive_sort(1, 3, K);

    cout << ans.size() << '\n';
    for (auto ele: ans) {
        cout << ele;
    }
}