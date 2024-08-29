//
// Created by 서정윤 on 2024. 8. 29..
//
#include <iostream>

using namespace std;

char stars[3073][6145]; // 가로 길이를 잘못 지정해주었다. 잘 확인하자.

void recursive_print_star(int, int, int);

void draw_triangle(int x, int y) {
    stars[y][x + 2] = '*';
    stars[y + 1][x + 1] = '*';
    stars[y + 1][x + 3] = '*';
    stars[y + 2][x] = '*';
    stars[y + 2][x + 1] = '*';
    stars[y + 2][x + 2] = '*';
    stars[y + 2][x + 3] = '*';
    stars[y + 2][x + 4] = '*';
}

void recursive_print_star(int n, int x, int y) {
    if (n == 3) {
        draw_triangle(x, y);
        return ;
    }
    int offset = n / 2;
    recursive_print_star(offset, x + 2 * offset, y + offset);
    recursive_print_star(offset, x + offset, y);
    recursive_print_star(offset, x, y + offset);
}

int main() {

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j)
            stars[i][j] = ' ';
    }

    recursive_print_star(N, 0, 0);

    for (int i = 0; i < N; ++i) {
            cout << stars[i] << '\n';
    }
    return 0;
}