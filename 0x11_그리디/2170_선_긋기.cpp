//
// Created by 서정윤 on 2024. 10. 4. 오후 7:56
//
#include <bits/stdc++.h>

using namespace std;
pair<int, int> input[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i].first >> input[i].second;
    }
    sort(input, input + N);
    int s = input[0].first, e = input[0].second;

    int len = 0;
    for (int i = 1; i < N; ++i) {
        // 기존 선의 연장: start가 end보다 작으면서 end가 큰 경우
        // 새로운 선분: 기존 end가 현재 start보다 작은 경우
        if (input[i].first <= e) {
            if (e < input[i].second) {
                e = input[i].second;
            }
        } else {
            len += e - s;
            s = input[i].first;
            e = input[i].second;
        }
    }
    len += e - s;
    cout << len;

}