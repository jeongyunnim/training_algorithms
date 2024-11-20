//
// Created by 서정윤 on 2024. 11. 20. 오후 3:37
//
#include <bits/stdc++.h>

using namespace std;
int dp[5001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    if (input[0] == '0') {
        cout << 0;
        return 0;
    }
    if (input.size() == 1) {
        cout << 1;
        return 0;
    }
    dp[0][0] = 1;
    dp[1][0] = input[1] == '0'? 0 : 1;
    dp[1][1] = stoi(input.substr(0,2)) < 27 ? 1 : 0;
    for (int i = 2; i < input.size(); ++i) {
        if (input[i] == '0') {
            // 0인 경우 홀로 올 수 없음
            if (input[i - 1] == '1' || input[i - 1] == '2')
                dp[i][1] = dp[i - 2][0] + dp[i - 2][1]; // 이전 값이 홀로 오는 것 배제
            else
                break ;
        } else {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            if (input[i - 1] == '1' || (input[i - 1] == '2' && input[i] < '7'))
                dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
        }
        dp[i][0] %= 1000000;
        dp[i][1] %= 1000000;
    }
//    for (int i = 0; i < input.size(); ++i) {
//        cout << input[i] << ' ';
//    }
//    cout << '\n';
//    for (int i = 0; i < input.size(); ++i) {
//        cout << dp[i][0] << ' ';
//    }
//    cout << '\n';
//    for (int i = 0; i < input.size(); ++i) {
//        cout << dp[i][1] << ' ';
//    }
//    cout << '\n';

    cout << (dp[input.size() - 1][0] + dp[input.size() - 1][1]) % 1000000;
}