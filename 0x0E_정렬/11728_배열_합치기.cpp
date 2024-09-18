//
// Created by 서정윤 on 2024. 9. 18. 오후 3:16
//
#include <iostream>

using namespace std;

int N, M;
int input_a[1000001];
int input_b[1000001];
int res[2000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> input_a[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> input_b[i];
    }

    int offset_a = 0;
    int offset_b = 0;
    for (int i = 0; i < N + M; ++i) {
        if (offset_b == M)
            res[i] = input_a[offset_a++];
        else if (offset_a == N)
            res[i] = input_b[offset_b++];
//        else if (input_a[offset_a] < input_b[offset_b]) -> stable sort(순서를 보장하는 정렬)을 위해서는 등호가 들어가는 것이 좋다.
        else if (input_a[offset_a] <= input_b[offset_b])
            res[i] = input_a[offset_a++];
        else
            res[i] = input_b[offset_b++];
        cout << res[i] << ' ';
    }


}