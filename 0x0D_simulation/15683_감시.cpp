//
// Created by 서정윤 on 2024. 9. 5..
//
#include <iostream>
#include <cstring>

using namespace std;

typedef struct s_cctv
{
    int x;
    int y;
    int type;
    int dir;
} t_cctv;

enum dir {
    UP = 0,
    RI,
    DO,
    LE,
};

int input[9][9];
bool visited[9][9];
t_cctv cctv[8];
int cctv_len;
int N, M, black;

void draw_white(int x, int y, int dir) {
    if (dir == UP) {
        for (int i = x; i >= 0; --i) {
            if (input[i][y] == 6)
                return ;
            visited[i][y] = 1;
        }
    }
    else if (dir == RI) {
        for (int i = y; i < M; ++i) {
            if (input[x][i] == 6)
                return;
            visited[x][i] = 1;
        }
    }
    else if (dir == DO) {
        for (int i = x; i < N; ++i) {
            if (input[i][y] == 6)
                return ;
            visited[i][y] = 1;
        }
    }
    else {
        for (int i = y; i >= 0; --i) {
            if (input[x][i] == 6)
                return ;
            visited[x][i] = 1;
        }
    }
}

void count_white_zone() {
    for (int i = 0; i < N; ++i) {
        bzero(visited[i], sizeof(visited[i]));
    }
    for (int i = 0; i < cctv_len; ++i) {
        if (cctv[i].type == 5) {
            draw_white(cctv[i].x, cctv[i].y, UP);
            draw_white(cctv[i].x, cctv[i].y, DO);
            draw_white(cctv[i].x, cctv[i].y, LE);
            draw_white(cctv[i].x, cctv[i].y, RI);
        }
        else if (cctv[i].type == 1) {
            draw_white(cctv[i].x, cctv[i].y, cctv[i].dir);
        }
        else if (cctv[i].type == 2) { // 문제 조건을 잘 보자. 2번 카메라와 3번 카메라가 바뀌었었다.
            draw_white(cctv[i].x, cctv[i].y, cctv[i].dir);
            draw_white(cctv[i].x, cctv[i].y, (cctv[i].dir + 2) % 4);
        }
        else if (cctv[i].type == 3) {
            draw_white(cctv[i].x, cctv[i].y, cctv[i].dir);
            draw_white(cctv[i].x, cctv[i].y, (cctv[i].dir + 1) % 4);
        }
        else {
            draw_white(cctv[i].x, cctv[i].y, cctv[i].dir);
            draw_white(cctv[i].x, cctv[i].y, (cctv[i].dir + 1) % 4);
            draw_white(cctv[i].x, cctv[i].y, (cctv[i].dir + 2) % 4);
        }
    }
}

void recursive_find_maximum_white(int n) {
    // type1: 단방향
    // type2: 양방향
    // type3: 직각
    // type4: T
    // type5: 전방향

    if (n == cctv_len) {
        // count white
        int count_black = 0;
        count_white_zone();
//        cout << "[visited]\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
//                if (input[i][j] == 6)
//                    cout << "|" << ' ';
//                else
//                    cout << visited[i][j] << ' ';
                if (visited[i][j] == 0 && input[i][j] == 0)
                    count_black += 1;
            }
//            cout << '\n';
        }
//        cout << "count: " << count_black << '\n';
        black = min(black, count_black);
        return ;
    }

    if (cctv[n].type == 5)
        recursive_find_maximum_white(n + 1);
    else {
        for (int i = 0; i < 4; ++i) {
            cctv[n].dir = i;
            recursive_find_maximum_white(n + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> input[i][j];
            if (input[i][j] != 0 && input[i][j] != 6) {
                cctv[cctv_len].x = i;
                cctv[cctv_len].y = j;
                cctv[cctv_len].type = input[i][j];
                cctv_len += 1;
            }
        }
    }
    black = 100;
    recursive_find_maximum_white(0);
    cout << black;
}