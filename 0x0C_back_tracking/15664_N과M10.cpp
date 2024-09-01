//
// Created by 서정윤 on 2024. 9. 1..
//
#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int input[9];
int seq[9];
bool issued[9];

void recursive_compose(int cur, int ptr) {
    if (cur == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    int dup = -1;
    for (int i = ptr; i < N; ++i) {
        if (issued[i] || dup == input[i]) // 같은 자리에 중복된 값이 들어가는 것만 막으면 된다.
            continue ;
        seq[cur] = input[i];
        dup = input[i];
        issued[i] = true;
        recursive_compose(cur + 1, i);
        issued[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input, input + N);

    recursive_compose(0, 0);
    return 0;
}