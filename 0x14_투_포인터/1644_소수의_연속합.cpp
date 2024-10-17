//
// Created by 서정윤 on 2024. 10. 17. 오후 3:08
//
#include <bits/stdc++.h>

using namespace std;
long long N;
vector<int> primes;
bool is_prime[40000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    if (N == 1) {
        cout << 0;
        return 0;
    }
    memset(is_prime, 1, sizeof(is_prime));
    for (long long i = 2; i <= N; ++i) {
        if(!is_prime[i]) continue ;
        primes.push_back(i);
        for (long long j = i * i; j <= N; j += i) { // i * i 가 overflow
            if(!is_prime[j]) continue ;
            is_prime[j] = false;
        }
    }
    sort(primes.begin(), primes.end());
    int en = 0, cnt = 0;
    long long sum = primes[0];
    for (int st = 0; st < primes.size(); ++st) {
        while (en < primes.size() && sum < N) {
            en += 1;
            if (en < primes.size())
                sum += primes[en];
        }
        if (sum == N) {
            cnt += 1;
        }
        if (en >= primes.size()) break ;
        sum -= primes[st];
    }
    cout << cnt;
}

