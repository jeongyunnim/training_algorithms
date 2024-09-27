//
// Created by 서정윤 on 2024. 9. 25. 오후 1:24
//
#include <iostream>

using namespace std;
enum{T, P};

int N, mx;
int counsel[1500001][2];
int selectable[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> counsel[i][T] >> counsel[i][P];
    }
    for (int day = 1; day <= N; ++day) {
        int potential = day + counsel[day][T] - 1;
        // 현재 선택할 수 있는 값 중 가장 큰 값을 가져온다.
        // selectable에서 유효한 값이 10 밖에 없는 경우
        // {10, 0, 0, 0, 0, 0, 0} 이 예상되는 경우 {10, 10, 10, 10, 10 ...} 으로 초기화 해주며 진행
        if (selectable[day] < selectable[day - 1])
            selectable[day] = selectable[day - 1];
        // 현재 선택할 수 있는 값 중 가장 높은 값을 더한다.
        // 오늘 상담 선택할 시 받는 기댓값과 이미 이전 날짜에 의해 초기화 되어있는 값과 비교한다.
        if (potential < N + 1 && selectable[potential] < selectable[day - 1] + counsel[day][P])
            selectable[potential] = selectable[day - 1] + counsel[day][P];
    }
    cout << selectable[N];
}