//
// Created by 서정윤 on 2024. 11. 18. 오후 3:38
//
#include <bits/stdc++.h>

enum {
    UP = 1,
    DO,
    RI,
    LE,
};

typedef struct s_info {
    int x;
    int y;
    int spd;
    int dir;
    int size;
    int cur;
} info;

using namespace std;
int R, C, M, field[101][101], ans;
vector<info> sharks;

/*
    다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다.
    (r, c)는 상어의 위치,
    s는 속력,
    d는 이동 방향,
    z는 크기이다.
    d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
 */

void catch_shark(int column) {
    column += 1;
    vector<info>::iterator nearest = sharks.end();
    int cur = 0x7fffffff;
    for (auto sh = sharks.begin(); sh != sharks.end(); ++sh) {
        if (sh->y == column && sh->x < cur) {
            cur = sh->x;
            nearest = sh;
        }
    }
    if (nearest != sharks.end()) {
//        cout << column << "] caught shark: " << nearest->x << ", " << nearest->y << ": " << nearest->size << '\n';
        ans += nearest->size;
        sharks.erase(nearest);
    }
}

void move_shark() {
    memset(field, 0, sizeof(field));
    for (auto sh = sharks.begin(); sh != sharks.end();++sh) {
        if (sh->dir <= 2) {
            // x
            if (R != 1) {
                sh->cur = (sh->cur + sh->spd - 1) % (2 * R - 2) + 1;
                if (sh->cur > R)
                    sh->x = 2 * R - sh->cur;
                else
                    sh->x = sh->cur;
            }
        } else {
            // y
            if (C != 1) {
                sh->cur = (sh->cur + sh->spd - 1) % (2 * C - 2) + 1;
                if (sh->cur > C)
                    sh->y = 2 * C - sh->cur;
                else
                    sh->y = sh->cur;
            }
        }

        if (field[sh->x][sh->y] < sh->size) {
            field[sh->x][sh->y] = sh->size;
        }
    }
//    cout << "[field]\n";
//    for (int i = 1; i <= R; ++i) {
//        for (int j = 1; j <= C; ++j) {
//            cout << field[i][j] << " ";
//        }
//        cout << '\n';
//    }
    for (auto sh = sharks.begin(); sh != sharks.end();) {
        if (field[sh->x][sh->y] != sh->size) {
            sh = sharks.erase(sh);
        } else {
            ++sh;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    // 1. 현재 진행 중인 y에서 x가 가장 작은 값 삭제
    // 2. 상어 이동
    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z, cur;
        cin >> r >> c >> s >> d >> z;
        if (d == 1) {
            // x += -1 * dir
            cur = (2 * R - r) % (2 * R - 2);
        } else if (d == 2) {
            // x += 1
            cur = r;
        } else if (d == 3) {
            // y += -1
            cur = c;
        } else {
            // y += 1
            cur = (2 * C - c) % (2 * C - 2);
        }
        sharks.push_back({r, c, s, d, z, cur});
    }
    for (int i = 0; i < C; ++i) {
        catch_shark(i);
        move_shark();
    }
    cout << ans;
}

/*
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5
 */