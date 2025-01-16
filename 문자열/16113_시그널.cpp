//
// Created by 서정윤 on 2025. 1. 15. 오전 11:05
//
#include <bits/stdc++.h>

using namespace std;

string type[10] = {
    "######...######",
    "#####",
    "#.####.#.####.#",
    "#.#.##.#.######",
    "###....#..#####",
    "###.##.#.##.###",
    "######.#.##.###",
    "#....#....#####",
    "######.#.######",
    "###.##.#.######"
};

string nums[20000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string input;

    cin >> N;
    cin >> input;

    string cur;
    for (int i = 0; i < N / 5; ++i) {
        string col;
        int line = i % (N / 5);
        bool is_blank = true;
        for (int j = 0; j < 5; ++j) {
            col.push_back(input[line + (N / 5 * j)]);
            if (input[line + (N / 5 * j)] == '#')
                is_blank = false;
        }
//        cout << "cur: " << cur << '\n';
        if (is_blank || i == (N / 5 - 1)) {
            if (i == (N / 5 - 1))
                cur += col;
            for (int num = 0; num < 10; ++num) {
                if (cur == type[num]) {
                    cout << num;
                    break ;
                }
            }
            cur.clear();
        } else {
            cur += col;
        }
    }
}