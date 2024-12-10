//
// Created by 서정윤 on 2024. 12. 9. 오후 5:54
//
#include <bits/stdc++.h>

using namespace std;
int dp[1002][1002];
char a[1001], b[1001];
char ans[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    int i = 0, j = 0, a_len = strlen(a), b_len = strlen(b);
    for (; a[i] != '\0'; ++i) {
        j = 0;
        for (; b[j] != '\0'; ++j) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                if (dp[i + 1][j] > dp[i][j + 1])
                    dp[i + 1][j + 1] = dp[i + 1][j];
                else
                    dp[i + 1][j + 1] = dp[i][j + 1];
            }
        }
        cout << j << " ";
    }
    cout << i << " " << j << '\n';
    cout << a_len << " " << b_len << '\n';
    cout << dp[i][j] << '\n';
    if (dp[i][j] == 0) return 0;

    int mx = dp[i][j];
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            if (dp[i][j] == dp[i - 1][j - 1] + 1) {
                ans[--mx] = a[i - 1];
            }
            i -= 1;
            j -= 1;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i -= 1;
        } else {
            j -= 1;
        }
    }
    cout << ans;
}