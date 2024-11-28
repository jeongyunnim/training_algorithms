//
// Created by 서정윤 on 2024. 11. 28. 오후 2:16
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    set<string> S;

    for (int i = 1; i <= input.size(); ++i) {
        for (int j = 0; i + j <= input.size(); ++j) {
            S.insert(input.substr(j, i));
//            cout << input.substr(j, i) << " ";
        }
    }
//    for (auto el : S)
//        cout << el << " ";
    cout << S.size();
}