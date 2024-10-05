//
// Created by 서정윤 on 2024. 10. 5. 오후 1:52
//
#include <bits/stdc++.h>

using namespace std;
int N, K, x, cnt;
int input[101];
int input_pos[101][101]; // 각 값이 가지는 모든 위치
pair<int, int> input_offset[101]; // 각 값이 가지는 최댓값
bool hole[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> x;
        input[i] = x;
        // 언제 나타났는지, 해당 항목에 대한 값을 하나씩 넣을 수 있어야 함.
        input_pos[x][input_offset[x].second++] = i;
    }
    int hole_cnt = 0;
    for (int i = 0; i < K; ++i) {
        if (hole_cnt < N) {
            if (!hole[input[i]]) {
                hole[input[i]] = true;
                hole_cnt += 1;
            }
            input_offset[input[i]].first += 1;
        } else {
            if (hole[input[i]]) {
                input_offset[input[i]].first += 1;
                continue ;
            }
            int mx = 0, mx_i = 0;
            for (int j = 1; j < 101; ++j) {
                if (!hole[j]) continue ;
                if (input_offset[j].first == input_offset[j].second) {
                    mx_i = j;
                    break ;
                }
                if (mx < input_pos[j][input_offset[j].first]) {
                    mx = input_pos[j][input_offset[j].first];
                    mx_i = j;
                }
            }
            hole[mx_i] = false;
            hole[input[i]] = true;
            input_offset[input[i]].first += 1;

            cnt += 1;
        }
    }
    cout << cnt;
}