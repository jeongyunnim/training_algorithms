#include <bits/stdc++.h>

using namespace std;
int DP[31][31];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        DP[i][1] = 1;
        for (int j = 2; j < i; ++j) {
            DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
        }
        DP[i][i] = 1;
    }
    cout << DP[N][K];
}