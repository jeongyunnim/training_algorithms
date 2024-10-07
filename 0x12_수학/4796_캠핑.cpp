//
// Created by 서정윤 on 2024. 10. 7. 오후 4:11
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P, L, V;

    int i = 1;
    while (true) {
        cin >> P >> L >> V;
        if (P + L + V == 0)
            break ;
        cout << "Case " << i++ << ": " << P * (V / L) + min(V % L, P) << '\n';
    }
}