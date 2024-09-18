//
// Created by 서정윤 on 2024. 9. 18. 오후 2:33
//
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    set<string> S;

    cin >> input;
    for (int i = 0; i < input.size(); ++i) {
        S.insert(input.substr(i));
    }
    for (auto el: S) {
        cout << el << '\n';
    }
}