//
// Created by 서정윤 on 2024. 8. 18..
//
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_VAL 80001
int nums[MAX_VAL];


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, count = 0;
    long long sum = 0; // sum의 범위는 21억이 넘을 수도 있다.
    stack<pair<int, long long> > S;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> nums[i];
    // 거꾸로 살펴본다.
    for (int i = n - 1; i >= 0; --i) {
        count = 0;
        // top의 높이가 현재 높이보다 높으면 해당 건물을 볼 수 있으므로 pair의 second를 늘려준다.
        while (!S.empty() && S.top().first < nums[i]) {
            // 비교하는 건물보다 낮은 건물들은 모두 볼 수 있으므로 count를 pair에 삽입해준다.
            count += S.top().second + 1;
            S.pop();
        }
        //
        S.push({nums[i], count});
        // 현재 건물에 대한 count를 총 합계에 더해준다.
        sum += count;
    }
    cout << sum;
    return 0;
}