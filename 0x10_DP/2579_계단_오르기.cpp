//
// Created by 서정윤 on 2024. 9. 21. 오후 8:49
//
#include <iostream>

using namespace std;

int stairs[301];
int max_score[301]; // [stair_number]

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, total = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> stairs[i + 1];
        total += stairs[i + 1];
    }

    /**
     * k 계단을 밟았을 때 1칸 2칸에 대한 최고 점수
        // max_score[k][1] = max(max_score[k-2][1], max_score[k-2][2]) + stairs[k];
        // max_score[k][2] = max_score[k-1][1] + stairs[k];
        max_score[1][1] = stairs[1];
        max_score[1][2] = 0;
        max_score[2][1] = stairs[2];
        max_score[2][2] = stairs[1] + stairs[2];

        for (int i = 3; i <= N; ++i) {
            max_score[i][1] = max(max_score[i-2][1], max_score[i-2][2]) + stairs[i];
            max_score[i][2] = max_score[i-1][1] + stairs[i];
        }
        cout << max(max_score[N][1], max_score[N][2]);
    */
    /**
     * k 계단을 안 밟았을 때 최소 값
     * k - 1 계단은 반드시 밟음.
     * 한 칸을 밟았거나 두 칸을 밟은 상태여야 한다.
     * k - 2 또는 K - 3의 max 값을 가져야 함.
     *
     */
    max_score[1] = stairs[1];
    max_score[2] = stairs[2];
    max_score[3] = stairs[3];
    for (int i = 4; i < N; ++i) {
        max_score[i] = min(max_score[i - 3], max_score[i - 2]) + stairs[i];
    }
    cout << total - min(max_score[N - 1], max_score[N - 2]);
}