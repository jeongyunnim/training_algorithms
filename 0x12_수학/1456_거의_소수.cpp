//
// Created by 서정윤 on 2024. 12. 28. 오후 1:58
//
#include <bits/stdc++.h>

using namespace std;
vector<bool> is_prime(10000001, true);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;

    is_prime[1] = false;
    for (long long i = 2; i <= sqrt(B); ++i) {
        if (!is_prime[i]) continue;
        is_prime[i] = true;
        for (long long j = i * i; j <= sqrt(B); j += i) { // 자료형 차이로 overflow
            is_prime[j] = false; // index 삽입 실수
        }
    }
    int cnt = 0;
    for (long long i = 2; i <= sqrt(B); ++i) {
        if (!is_prime[i]) continue ;
        long long temp = i * i;
        while (temp <= B) {
            if (temp >= A) {
                cnt += 1;
            }
            if (temp > B / i) break ;
            temp *= i;
        }
    }
    cout << cnt;
}