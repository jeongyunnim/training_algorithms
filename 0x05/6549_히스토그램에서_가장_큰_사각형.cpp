//
// Created by 서정윤 on 2024. 9. 29. 오후 3:07
//
#include <bits/stdc++.h>

#define VAL first
#define CNT second
using namespace std;

int histogram[100001];
stack<pair<long long, int> > S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long mx;
    while (true) {
        cin >> N;
        if (N == 0)
            return 0;
        for (int i = 0; i < N; ++i) {
            cin >> histogram[i];
        }
        mx = 0;
        histogram[N] = -1;
        S = stack<pair<long long, int> >();

        S.push({histogram[0], 1});
        for (int i = 1; i <= N; ++i) {
            int temp = 0;
            while (!S.empty() && S.top().VAL > histogram[i]) {
                temp += S.top().CNT;
                mx = max(mx, S.top().VAL * temp);
                S.pop();
            }
            if (!S.empty() && S.top().VAL == histogram[i])
                S.top().CNT += temp + 1;
            else
                S.push({histogram[i], 1 + temp});
        }
        cout << mx << '\n';
    }
}