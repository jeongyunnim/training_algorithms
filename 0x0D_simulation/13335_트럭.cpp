//
// Created by 서정윤 on 2024. 9. 9..
//
#include <iostream>

using namespace std;

int N, W, L, total;
int trucks[1001];
int crossed[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W >> L;
    for (int i = 0; i < N; ++i) {
        cin >> trucks[i];
    }

    int current_weight = 0;
    int offset = 0;
    int crossing_cnt = 0;
    int i = 0;
    while (offset < N) {
        // 건넌 트럭은 무게에서 빼준다.
        if (crossed[offset] == W) {
            current_weight -= trucks[offset];
            crossing_cnt -= 1;
            offset += 1;
        }
        // 다음 트럭을 올릴 수 있으면 올린다.
        if (current_weight + trucks[i] <= L) {
            current_weight += trucks[i];
            crossing_cnt += 1;
            i++;
        }
        // 시간을 증가시킨다.
        total += 1;
        for (int j = 0; j < crossing_cnt; ++j) {
            crossed[offset + j] += 1;
        }
    }
    cout << total;
}
