//
// Created by 서정윤 on 2024. 9. 1..
//
#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int input[9];
int seq[9];

void recursive_compose(int cur) {
    if (cur == M) {
        for (int i = 0; i < M; ++i) {
            cout << seq[i] << ' ';
        }
        cout << '\n';
        return ;
    }

    for (int i = 0; i < N; ++i) {
        seq[cur] = input[i];
        recursive_compose(cur + 1);
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

    recursive_compose(0);
    return 0;
}