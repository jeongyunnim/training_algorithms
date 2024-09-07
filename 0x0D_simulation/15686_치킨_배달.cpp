//
// Created by 서정윤 on 2024. 9. 7..
//
#include <iostream>
#include <algorithm>
#include <cmath>
#define X first
#define Y second
using namespace std;
pair<int, int> chicken[14];
int chicken_len;
pair<int, int> houses[100];
int open[14];
int houses_len;
int N, M, x, mn = INT32_MAX;

int cal_chicken_len() {
    int cal = 0;

    for (int i = 0; i < houses_len; ++i) {
        int current_mn = INT32_MAX;
        for (int j = 0; j < M; ++j) {
//            cout << "집: " << houses[i].X << ',' << houses[i].Y << " && 치킨집: " << chicken[open[j]].X << ',' << chicken[open[j]].Y << ':';
//            cout << "mn: " << abs(houses[i].X - chicken[open[j]].X) + abs(houses[i].Y - chicken[open[j]].Y) << '\n';
            current_mn = min(abs(houses[i].X - chicken[open[j]].X) + abs(houses[i].Y - chicken[open[j]].Y), current_mn); // 두 점 사이의 거리공식을 잘 보자.
        }
        cal += current_mn;
    }
    return cal;
}

void recursive_comb(int n, int cur) {
    if (n == M) {
        mn = min(cal_chicken_len(), mn);
        return ;
    }
    if (cur >= chicken_len) return ;

    recursive_comb(n, cur + 1); // 선택하지 않은 경우
    open[n] = cur;

    recursive_comb(n + 1, cur + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N * N; ++i) {
        cin >> x;
        if (x == 2) {
            chicken[chicken_len].X = i / N;
            chicken[chicken_len].Y = i % N;
            chicken_len += 1;
        }
        else if (x == 1) {
            houses[houses_len].X = i / N;
            houses[houses_len].Y = i % N;
            houses_len += 1;
        }
    }

    recursive_comb(0, 0);
    cout << mn;
}
