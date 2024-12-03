//
// Created by 서정윤 on 2024. 12. 3. 오후 4:45
//
#include <bits/stdc++.h>

using namespace std;
int N, M;
/**
 * DP 배열은 정답을 저장하는 것이 아닌,
 * "순환이 없을 때" N개의 요소에서 M개를 고르는 모든 경우의 수를 저장할 배열이다.
 * 해당 원소를 선택했을 때와 선택하지 않았을 때의 경우의 합을 저장한다.
 */
int dp[1001][1001];
const int mod = 1000000003;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i <= N; ++i) {
        /** dp[i][0] = 1 에 대한 설명
         * M이 1일 때의 예외처리를 위함이다.
         * dp[N - 3][M - 1]    + dp[N - 1][M]
         * 마지막 원소를 선택했을 때 + 선택하지 않았을 때
         * 0을 1로 초기화 해주는 것은 M이 1개일 때 이미 마지막 원소를 선택했기 때문에 남은 원소를 선택할 수 없는 경우이다.
         * 다시말해, "마지막 원소를 선택했다"는 의미에서 1로 초기화 한다.
        */
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i < N; ++i) {
        for (int j = 2; j <= N / 2 && j <= M; ++j) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    cout << (dp[N - 3][M - 1] + dp[N - 1][M]) % mod;
}