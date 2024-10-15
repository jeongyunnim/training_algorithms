//
// Created by 서정윤 on 2024. 10. 14. 오후 8:49
//
#include <bits/stdc++.h>

using namespace std;
int N;
int input[1001];
vector<int> two;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N);
    // 2씩 짝짓기
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            two.push_back(input[i] + input[j]);
        }
    }
    sort(two.begin(), two.end());
    for (int i = N - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (binary_search(two.begin(), two.end(), input[i] - input[j])) {
                cout << input[i];
                return 0;
            }
        }
    }
}