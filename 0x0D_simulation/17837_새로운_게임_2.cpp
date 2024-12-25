//
// Created by 서정윤 on 2024. 12. 25. 오후 7:00
//
#include <bits/stdc++.h>

using namespace std;

enum DIR {
    RI,
    LE,
    UP,
    DO
};

typedef struct s_horse {
    int x;
    int y;
    int dir;
    int num;
} horse;

typedef struct s_info {
    int type;
    list<horse> order;
} info;

int N, K;
info board[13][13];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
horse horses[11];

void switch_dir(horse &tar) {
    if (tar.dir == LE) {
        tar.dir = RI;
    } else if (tar.dir == RI) {
        tar.dir = LE;
    } else if (tar.dir == UP) {
        tar.dir = DO;
    } else {
        tar.dir = UP;
    }
}

void print_dir(int dir) {
    if (dir == LE)
        cout << "LE[0,-1]";
    else if (dir == RI)
        cout << "RI[0,+1]";
    else if (dir == UP)
        cout << "UP[-1,0]";
    else
        cout << "DO[+1,0]";
}

void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j].order.front().num << "." << board[i][j].order.size() << " ";
        }
        cout << '\n';
    }
}

bool move() {
    for (int i = 1; i <= K; ++i) {
        auto cur = horses[i];
        bool is_red = false;
        auto it = board[cur.x][cur.y].order.begin();
        for (; it != board[cur.x][cur.y].order.end(); it++) {
            if (it->num == i) break ;
        }

        int nx = it->x + dx[it->dir];
        int ny = it->y + dy[it->dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny].type == 2) {
            // blue
            switch_dir(*it);
            horses[it->num].dir = it->dir;
            nx = it->x + dx[it->dir];
            ny = it->y + dy[it->dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny].type == 2) continue;
        }
        if (board[nx][ny].type == 1) {
            is_red = true;
        }

        list<horse> tar;
        while (it != board[it->x][it->y].order.end()) {
            if (is_red)
                tar.push_front(horses[it->num]);
            else
                tar.push_back(horses[it->num]);
            it = board[it->x][it->y].order.erase(it);
        }
        it = tar.begin();
        while (it != tar.end()) {
            horses[it->num].x = nx;
            horses[it->num].y = ny;
            board[nx][ny].order.push_back(horses[it->num]);
            ++it;
        }
        if (board[nx][ny].order.size() > 3)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int type;
            cin >> type;
            board[i][j].type = type;
        }
    }
    for (int i = 1; i <= K; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        horses[i] = {x - 1, y - 1, d - 1, i};
        board[x - 1][y - 1].order.push_back(horses[i]);
    }
    int turn = 0;
    while (turn < 1000) {
        turn += 1;
        if (move())
            break ;
    }
    if (turn == 1000)
        cout << -1;
    else
        cout << turn;
}