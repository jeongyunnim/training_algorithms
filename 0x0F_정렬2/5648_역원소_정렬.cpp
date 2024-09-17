//
// Created by 서정윤 on 2024. 9. 17. 오후 3:24
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long reverse_input(char input[13]) {
    long long res = 0;
    size_t size = strlen(input);
    for (int i = size - 1; i >= 0; --i) {
        res *= 10;
        res += (input[i] - '0');
    }
    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    char input[13];
    vector<long long> V;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        V.push_back(reverse_input(input));
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < N; ++i) {
        cout << V[i] << '\n';
    }
}