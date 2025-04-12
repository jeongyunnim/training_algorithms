//
// Created by 서정윤 on 2025. 4. 12. 오전 10:38
//
#include <bits/stdc++.h>

using namespace std;
enum
{
    LE = 0,
    DO,
    RI,
    UP
};
typedef struct info_t
{
    int x;
    int y;
    int dir;
    int mov;
    int cnt;
} info;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int dix[4][10] = {
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
        {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1},
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0},
        {1, 1, 0, 0, -1, -1, 0, 0, -2, -1}
};
const int diy[4][10] = {
        {1, 1, 0, 0, -1, -1, 0, 0, -2, -1},
        {-1, 1, -1, 1, 1, -1, -2, 2, 0, 0},
        {-1, -1, 0, 0, 1, 1, 0, 0, 2, 1},
        {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}
};
const int wei[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5};
int board[500][500];
int N;
info cur;
int ans;

void init()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
    cur.dir = LE;
    cur.mov = 0;
    cur.cnt = 0;
    cur.x = cur.y = N / 2;
}

void calNextMove()
{
    if (cur.mov == cur.cnt)
    {
        cur.dir = (cur.dir + 1) % 4;
        cur.cnt = 0;
        if (cur.dir == RI || cur.dir == LE)
            cur.mov += 1;
    }
    else
    {
        cur.cnt += 1;
    }
}

void scatterDust()
{
    int curDust = board[cur.x][cur.y];
    board[cur.x][cur.y] = 0;
    if (curDust == 0) {
        return ;
    }
    int a = 0;
    for (int i = 0; i < 10; ++i)
    {
        int tarx = cur.x + dix[cur.dir][i];
        int tary = cur.y + diy[cur.dir][i];
        int amount = 0;

        if (i == 9)
            amount = curDust - a;
        else
            amount = curDust * wei[i] / 100;
        if (amount == 0) continue ;
        a += amount;
        if (tarx < 0 || tarx >= N || tary < 0 || tary >= N)
        {
            ans += amount;
            continue ;
        }
        board[tarx][tary] += amount;
    }
}

void move()
{
    cur.x += dx[cur.dir];
    cur.y += dy[cur.dir];
}

void fire()
{
    while (!(cur.x == 0 && cur.y == 0))
    {
        move();
        scatterDust();
        calNextMove();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    fire();
    cout << ans << '\n';
}