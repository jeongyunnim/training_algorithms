//
// Created by 서정윤 on 2024. 10. 17. 오후 4:48
//
#include <bits/stdc++.h>

using namespace std;

bool compare(const string &lhs, const string &rhs) {
    if (strcmp(lhs.c_str(), rhs.c_str()) >= 0)
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string name, status;
    unordered_set<string> S;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> name >> status;
        if (status[0] == 'e') {
            S.insert(name);
        } else {
            S.erase(name);
        }
    }
    vector<string> V(S.begin(), S.end());
    sort(V.begin(), V.end(), greater<string>());
    for (auto el : V) {
        cout << el << '\n';
    }
}