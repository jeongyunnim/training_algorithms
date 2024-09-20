//
// Created by 서정윤 on 2024. 9. 20. 오후 2:21
//
#include <iostream>
#include <stack>

using namespace std;

int input[500001];
stack<pair<int, int> > S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    long long cnt = 0;

    // top보다 작을 때 인접한 것만 볼 수 있음.
    // top보다 크면 해당 값이 하나씩 pop한 것들만 볼 수 있음.
    // 같은 값이 연속되면 더 큰 값의 연속은 볼 수 없음.
    // 같은 값보다 큰 값들은 연속된 같은 값들을 모두 볼 수 있음.
    // 답은 int의 범위를 벗어날 수 있음.

    S.push({input[0], 1});
    for (int i = 1; i < N; ++i) {
        // Top의 큰 값을 만날 때까지 증가
        while (!S.empty() && S.top().first < input[i]) {
            // 큰 값은 중복된 값을 모두 볼 수 있으므로 second 만큼 cnt 증가
            cnt += S.top().second;
            S.pop();
        }

        // top과 같은 값일 때 연속된 값을 모두 볼 수 있으므로 += top.second
        // 해당 값보다 큰 값이 스택에 있다면 += 1
        if (!S.empty() &&S.top().first == input[i]) {
            cnt += S.top().second;
            S.top().second += 1;
            if (S.size() > 1)
                cnt += 1;
            continue ;
        } else if (!S.empty()) {
            // 지금 값이 제일 큰 값이 아니라면 cnt += 1
            cnt += 1;
        }
        // 현재 값 push
        S.push({input[i], 1});
    }
    cout << cnt;
}
