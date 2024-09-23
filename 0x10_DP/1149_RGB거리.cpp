//
// Created by 서정윤 on 2024. 9. 23. 오후 3:23
//
#include <iostream>
#include <algorithm>

using namespace std;
enum {R, G, B};
int N;
int houses[1002][3];
int min_rate[1001][3];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> houses[i][R] >> houses[i][G] >> houses[i][B];
    }
    min_rate[1][R] = houses[1][R];
    min_rate[1][G] = houses[1][G];
    min_rate[1][B] = houses[1][B];
    for (int i = 2; i <= N; ++i) {
        min_rate[i][R] = min(min_rate[i - 1][G], min_rate[i - 1][B]) + houses[i][R];
        min_rate[i][G] = min(min_rate[i - 1][R], min_rate[i - 1][B]) + houses[i][G];
        min_rate[i][B] = min(min_rate[i - 1][R], min_rate[i - 1][G]) + houses[i][B];
    }
    cout << min({min_rate[N][R], min_rate[N][G], min_rate[N][B]});
}