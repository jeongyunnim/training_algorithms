//
// Created by 서정윤 on 2024. 9. 25. 오후 8:13
//
#include <iostream>

using namespace std;
long long stair_num[101][10];

int case_1[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i <= 9; ++i) {
        stair_num[1][i] = case_1[i];
    }

    for (int i = 2; i <= N; ++i) {
        stair_num[i][0] = stair_num[i - 1][1];
        stair_num[i][9] = stair_num[i - 1][8];
        for (int j = 1; j < 9; ++j) {
            stair_num[i][j] = (stair_num[i - 1][j - 1] + stair_num[i - 1][j + 1]) % 1000000000;
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        ans += stair_num[N][i];
        ans %= 1000000000;
    }
    cout << ans;
}