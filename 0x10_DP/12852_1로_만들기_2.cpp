//
// Created by 서정윤 on 2024. 9. 23. 오후 6:35
//
#include <iostream>
#include <algorithm>

using namespace std;

int ways[1000001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    ways[1][0] = 0;
    ways[1][1] = 0;
    ways[2][0] = 1;
    ways[2][1] = 1;
    for (int i = 3; i <= N; ++i) {
        int div_2 = INT32_MAX;
        int div_3 = INT32_MAX;
        ways[i][0] = ways[i - 1][0];
        if (i % 2 == 0) {
            div_2 = ways[i / 2][0];
        }
        if (i % 3 == 0) {
            div_3 = ways[i / 3][0];
        }

        ways[i][0] = min({ways[i][0], div_2, div_3});
        if (ways[i][0]  == div_2) {
            ways[i][1] = i / 2;
        } else if (ways[i][0] == div_3) {
            ways[i][1] = i / 3;
        } else {
            ways[i][1] = i - 1;
        }
        ways[i][0] += 1;
    }
    cout << ways[N][0] << '\n';

    int temp = N;
    cout << N << " ";
    while (temp > 1) {
        cout << ways[temp][1] << " ";
        temp = ways[temp][1];
    }
}