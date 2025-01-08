//
// Created by 서정윤 on 2025. 1. 8. 오전 1:23
//
#include <bits/stdc++.h>

using namespace std;
string input;
vector<pair<char, int> > V;
bool visited[101];

void print_ans() {
    for (int i = 0; i < input.size(); ++i) {
        if (!visited[i]) continue ;
        cout << input[i];
    }
    cout << '\n';
}

void solve(int n) {
    auto cur = V[n];
    print_ans();
    // n == v의 인덱스

    for (int i = n + 1; i < V.size(); ++i) {
        if (visited[V[i].second] || V[i].second < cur.second) continue ;
        visited[V[i].second] = true;
        solve(i);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;

    for (int i = 0; i < input.size(); ++i) {
        V.push_back({input[i], i});
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); ++i) {
        if (visited[V[i].second]) continue ;
        visited[V[i].second] = true;
        solve(i);
    }
}