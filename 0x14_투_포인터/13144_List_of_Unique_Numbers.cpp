//
// Created by 서정윤 on 2025. 1. 13. 오전 8:52
//
#include <bits/stdc++.h>

using namespace std;
int seq[100001];
//int weight[100001];
bool visited[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> seq[i];
    }
//    weight[1] = 1;
//    for (int i = 2; i <= N; ++i) {
//        weight[i] = weight[i - 1] + i;
//    }
    int s = 0, e = 0, chain = 0;
    long long sum = 0; // 자료형 확인 똑바로 할 것.
    while (s < N) {
        int cur;
        while (e < N) {
            cur = seq[e];
            if (visited[cur]) break ;
            visited[cur] = true;
            chain += 1;
            sum += chain;
            e += 1;
        }
        visited[seq[s]] = false;
        if (e != N)
            chain -= 1;
        s += 1;
    }

    cout << sum;
}