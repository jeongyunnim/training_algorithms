//
// Created by 서정윤 on 2024. 9. 17. 오후 4:03
//
#include <iostream>
#include <set>

using namespace std;

struct Compare {
    bool operator() (const string &a, const string &b) const {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    set<string, Compare> S;
    string input;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        S.insert(input);
    }

    for (auto el : S) {
        cout << el << '\n';
    }

}