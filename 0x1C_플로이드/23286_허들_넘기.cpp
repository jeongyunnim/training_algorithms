//
// Created by 서정윤 on 2025. 3. 5. 오후 10:02
//
#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;
int arr[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, T;

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i) {
        fill(arr[i] + 1, arr[i] + N + 1, MAX);
    }
    for (int i = 0; i < M; ++i) {
        int u, v, h;
        cin >> u >> v >> h;
        if (arr[u][v] > h) {
            arr[u][v] = h;
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int cur_mx = max(arr[i][k], arr[k][j]);
                if (arr[i][j] > cur_mx)
                {
                    arr[i][j] = cur_mx;
                }
            }
        }
    }

//    cout << '\n';
//    for (int i = 1; i <= N; ++i) {
//        for (int j = 1; j <= N; ++j) {
//            if (arr[i][j] == MAX)
//                cout << setw(3) << "-";
//            else
//            cout << setw(3) << arr[i][j];
//        }
//        cout << '\n';
//    }

    for (int i = 0; i < T; ++i) {
        int u, v;
        cin >> u >> v;
        if (arr[u][v] == MAX)
            cout << "-1\n";
        else
            cout << arr[u][v] << '\n';
    }
}