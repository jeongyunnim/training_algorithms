//
// Created by 서정윤 on 2025. 2. 8. 오후 7:13
//
#include <iostream>

using namespace std;

int planet[10][10];
int dp[10][2 << 10];
int N, K;

// TSP(Traveling Salesman Problem)
int find_least(int x, int visited) {
    if (visited == (1 << N) - 1) {
        // 전부 돌았을 때, 반환할 값: 돌아오지 않아도 되므로 0을 반환한다.
        // 돌아와야 하는 경우 planet[현재 위치][시작 위치]를 반환한다.
        return 0;
    }
    // 메모이제이션: 이미 값이 있는 경우 해당 값을 반환한다.
    // 그런데 이 값을 또 만나는 경우가 있을까?
    if (dp[x][visited])
        return dp[x][visited];
    // 최솟값을 찾기 위해 가질 수 있는 최댓값 이상의 값으로 초기화
    dp[x][visited] = 0x7fffffff;
    for (int i = 0; i < N; ++i) {
        if (x == i|| (visited & (1 << i))) continue;
        // 재귀적으로 임의의 노드를 결정했을 때의 최단 거리를 탐색한다.
        int temp = find_least(i, visited | (1 << i));
        dp[x][visited] = min(dp[x][visited], temp + planet[x][i]);
    }
    // x에서 임의의 노드로 향하는 최단 거리를 반환한다.
    return dp[x][visited];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int visited = 0;

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> planet[i][j];
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (planet[i][j] > planet[i][k] + planet[k][j])
                    planet[i][j] = planet[i][k] + planet[k][j];
            }
        }
    }
    visited |= (1 << K);
    cout << find_least(K, visited);
}