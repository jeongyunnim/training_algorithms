//
// Created by 서정윤 on 2024. 9. 3..
//
#include <iostream>
#include <algorithm>

using namespace std;

int N, mx;
int eggs[8][2];

void crash_egg(int *r, int *l) {
    r[0] -= l[1];
    l[0] -= r[1];
}

void count_crashed() {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
//        cout << "[" <<i << "]: " << eggs[i][0] << ' ';
        if (eggs[i][0] <= 0)
            cnt += 1;
    }
    if (mx < cnt)
        mx = cnt;
//    cout << "\ncnt: " << cnt << '\n';
}

void recursive_crash(int cur) {
//    cout << "현재 달걀: " << cur << '\n';
    if (cur >= N) {
        count_crashed();
        return;
    }
    if (eggs[cur][0] <= 0) {
        recursive_crash(cur + 1);
        return ;
    }
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (i == cur) continue ;
        if (eggs[i][0] <= 0) {
            continue ;
        }
//        cout << "cur[" << cur << "]:" << eggs[cur][0] << "가 [" << i << "]:" << eggs[i][1] << "를 친다 -> ";
        crash_egg(eggs[cur], eggs[i]);
//        cout << eggs[cur][0] << " && " << eggs[i][0] << " -- 남은 내구도.\n";
        recursive_crash(cur + 1);
        eggs[cur][0] += eggs[i][1];
        eggs[i][0] += eggs[cur][1];
        flag = true;
    }
    if (!flag)
        recursive_crash(cur + 1);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> eggs[i][0] >> eggs[i][1];
    }

    recursive_crash(0);
    cout << mx;
}