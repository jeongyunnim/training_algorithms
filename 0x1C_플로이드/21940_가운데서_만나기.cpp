//
// Created by 서정윤 on 2025. 2. 5. 오후 5:29
//
#include <bits/stdc++.h>

using namespace std;
int city[201][201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue ;
            city[i][j] = 0x7fffffff / 2;
        }
    }

    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        if (city[u][v] > t)
            city[u][v] = t;
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (city[i][j] > city[i][k] + city[k][j])
                    city[i][j] = city[i][k] + city[k][j];
            }
        }
    }

    int T;
    cin >> T;
    int friends[201];
    set<int> ans;
    for (int i = 0; i < T; ++i) {
        cin >> friends[i];
    }
    int mn = 0x7fffffff;
    for (int i = 1; i <= N; ++i) {
        int cur_mx = 0;
        for (int j = 0; j < T; ++j) {
            if (cur_mx < city[i][friends[j]] + city[friends[j]][i])
                cur_mx = city[i][friends[j]] + city[friends[j]][i];
        }
        if (mn > cur_mx) {
            mn = cur_mx;
            ans.clear();
            ans.insert(i);
        } else if (mn == cur_mx) {
            ans.insert(i);
        }
    }
    for (int el: ans)
        cout << el << " ";
}