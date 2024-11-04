//
// Created by 서정윤 on 2024. 11. 4. 오후 3:02
//
#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int board[10][10];
vector<pair<int, int> > blank;
vector<int> values;

bool return_flag;
bool area[10][10]; // 9개 공간 9개 숫자
bool row[10][10];
bool col[10][10];
/*
0 1 2
3 4 5
6 7 8
*/

bool valid_check(pair<int, int> cur, int v) {
    if (row[cur.X][v] || col[cur.Y][v] || area[cur.X / 3 * 3 + cur.Y / 3][v])
        return false;
    return true;
}

void turn_on(pair<int, int> cur, int v) {
    board[cur.X][cur.Y] = v;
    row[cur.X][v] = true;
    col[cur.Y][v] = true;
    area[cur.X / 3 * 3 + cur.Y / 3][v] = true;
}

void turn_off(pair<int, int> cur, int v) {
    row[cur.X][v] = false;
    col[cur.Y][v] = false;
    area[cur.X / 3 * 3 + cur.Y / 3][v] = false;
}

void solve(int n) {
    if (n == blank.size()) {
        return_flag = true;
        for (int i = 0; i < 81; ++i) {
            cout << board[i / 9][i % 9] << " ";
            if (i % 9 == 8) cout << '\n';
        }
        return ;
    }
    for (int i = 1; i <= 9; ++i) {
        if (return_flag) return ;
        if (valid_check(blank[n], i)) {
            turn_on(blank[n], i);
            values.push_back(i);
            solve(n + 1);
            turn_off(blank[n], i);
            values.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 81; ++i) {
        pair<int, int> cur(i / 9, i % 9);
        int val;

        cin >> val;
        board[i / 9][i % 9] = val;
        if (val == 0) {
            blank.push_back({i / 9, i % 9});
        } else {
            row[cur.X][val] = true;
            col[cur.Y][val] = true;
            area[(cur.X / 3 * 3) + (cur.Y / 3)][val] = true;
        }
    }
    solve(0);
}