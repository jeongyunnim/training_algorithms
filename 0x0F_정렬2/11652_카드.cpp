//
// Created by 서정윤 on 2024. 9. 17. 오후 2:07
//
#include <iostream>
#include <map>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long x;
    map<long long , int> M;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        M[x] += 1;
    }
    pair<long long , int> cur_max = {numeric_limits<long long>::max(), 0};
    for (auto el: M) {
        if (cur_max.second < el.second)
            cur_max = el;
        else if (cur_max.second == el.second && cur_max.first > el.first)
            cur_max = el;
    }
    cout << cur_max.first;
}