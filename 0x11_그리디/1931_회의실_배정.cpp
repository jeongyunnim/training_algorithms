//
// Created by 서정윤 on 2024. 9. 30. 오후 1:25
//
#include <bits/stdc++.h>

using namespace std;
int N;
pair<int ,int> input[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input[i].second >> input[i].first;
    }

    sort(input, input + N);

    int time = input[0].first;
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (time > input[i].second) continue ;
//        cout << input[i].first << " " << V[i].second << '\n';
        time = input[i].first;
        cnt += 1;
    }
    cout << cnt;
}