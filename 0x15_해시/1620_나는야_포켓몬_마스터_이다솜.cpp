//
// Created by 서정윤 on 2024. 10. 17. 오후 5:12
//
#include <bits/stdc++.h>

using namespace std;

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;
    string name;
    unordered_map<string, int> dic;
    string dic_i[100001];
    for (int i = 1; i <= N; ++i) {
        cin >> name;
        dic[name] = i;
        dic_i[i] = name;
    }
    string target;
    for (int i = 0; i < M; ++i) {
        cin >> target;
        if (is_digit(target[0])) {
            int num = stoi(target);
            cout << dic_i[num] << '\n';
        } else {
            cout << dic[target] << '\n';
        }
    }

}