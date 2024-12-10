//
// Created by 서정윤 on 2024. 12. 10. 오후 5:25
//
#include <bits/stdc++.h>

using namespace std;
int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<int> ans;
    int len = a.size();
    for (int i = 0; i < len; ++i) {
        ans.push_back(alpha[a[i] - 'A']);
        ans.push_back(alpha[b[i] - 'A']);
    }
    while (ans.size() > 2) {
        for (int i = 0; i < ans.size() - 1; ++i) {
            ans[i] = (ans[i] + ans[i + 1]) % 10;
        }
        ans.pop_back();
    }
    cout << ans[0] << ans[1];
}