//
// Created by 서정윤 on 2024. 9. 23. 오후 3:58
//
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
deque<pair<int, int> > D;
int input[5000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < N; ++i) {
        // while로 처리를 하지 않아도 되는 이유는?
        // index 순서대로 뒤로 삽입한다. == 앞에 있는 원소가 가장 오래된 원소
        // 가장 앞에 있는 원소를 제거할 때 해당 인덱스가 유효 범위를 벗어나는 즉시 제거된다.
        // 값과 등장한 순서가 오름차순으로 정렬이 되어있기 때문에 가능하다.
        if (!D.empty() && D.front().second + L <= i) {
            D.pop_front();
        }
        /**
         * 비교할 값보다 큰 요소를 삭제하고 자신으로 대체
         */
        while (!D.empty() && D.back().first >= input[i])
            D.pop_back();
        D.push_back({input[i], i});
        cout << D.front().first << " ";
    }
}