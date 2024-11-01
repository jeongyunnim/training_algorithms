//
// Created by 서정윤 on 2024. 11. 1. 오후 3:49
//
#include <bits/stdc++.h>

using namespace std;
int arr[101][101];

bool compare(const pair<int, int> lhs, const pair<int, int> rhs) {
    if (lhs.second != rhs.second)
        return lhs.second < rhs.second;
    else
        return lhs.first < rhs.first;
}

void op_r(int &r, int &c) {
    int temp[101][101];
    bzero(temp, sizeof(temp));
    for (int x = 0; x < r; ++x) {
        // 출현 횟수 세기
        unordered_map<int, int> M;
        for (int y = 0; y < c; ++y) {
            if (arr[x][y] == 0) continue ; // 가로 연산 시 세로 연산에 의해 0이 중간에 끼어있을 수 있다. break 하면 안 됨.
            M[arr[x][y]] += 1;
        }
        vector<pair<int, int> > V(M.begin(), M.end());
        // 정렬하기
        sort(V.begin(), V.end(), compare);
        // 출현 횟수 배열에 넣기
        if (c > 100)
            c = 100;
        int y = 0;
        for (auto el : V) {
            if (y > 100) break;
            temp[x][y++] = el.first;
            if (y > 100) break;
            temp[x][y++] = el.second;
        }
        c = max(c, y);
    }
    memcpy(arr, temp, sizeof(arr));
}

void op_c(int &r, int &c) {
    int temp[101][101];
    bzero(temp, sizeof(temp));
    for (int y = 0; y < c; ++y) {
        // 출현 횟수 세기
        unordered_map<int, int> M;
        M.clear();
        for (int x = 0; x < r; ++x) {
            if (arr[x][y] == 0) continue ;
            M[arr[x][y]] += 1;
        }
        vector<pair<int, int> > V(M.begin(), M.end());
        // 정렬하기
        sort(V.begin(), V.end(), compare);
        // 출현 횟수 배열에 넣기
        int x = 0;
        for (auto el : V) {
            if (x > 100) break;
            temp[x++][y] = el.first;
            if (x > 100) break;
            temp[x++][y] = el.second;
        }
        r = max(r, x);
    }
    memcpy(arr, temp, sizeof(arr));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, k, time = 0;
    cin >> r >> c >> k;
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i / 3][i % 3];
    }
    int cur_r = 3, cur_c = 3;
    while (arr[r - 1][c - 1] != k && time <= 100) { // '100 초가 지나도' 100초도 포함된다.
        if (cur_r >= cur_c) {
            // op_r
            op_r(cur_r, cur_c);
        } else {
            // op_l
            op_c(cur_r, cur_c);
        }
        time += 1;
//        cout << "[arr]" << cur_r << " * " << cur_c << '\n';
//        for (int i = 0; i < cur_c * cur_r; ++i) {
//            cout << arr[i / cur_c][i % cur_c] << " ";
//            if (i % cur_c == cur_c - 1) cout << '\n';
//        }
    }
    if (time > 100)
        time = -1;
    cout << time;
}