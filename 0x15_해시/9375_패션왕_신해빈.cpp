//
// Created by 서정윤 on 2024. 11. 28. 오후 1:04
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;
    while (T--) {
        map<string, int> M;

        cin >> N;
        string  name, parts;
        for (int i = 0; i < N; ++i) {
            cin >> name >> parts;
            M[parts] += 1;
        }
        int sum = 0;
        for (auto el: M) {
            if (sum) {
                sum *= el.second + 1;
            } else {
                sum = el.second + 1;
            }
        }
        if (sum == 0)
            cout << "0\n";
        else
            cout << sum - 1 << '\n';
    }
}
