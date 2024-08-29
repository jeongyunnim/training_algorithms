//
// Created by 서정윤 on 2024. 8. 29..
//
#include <iostream>

using namespace std;

char stars[2188][2188];

void recursive_print_star(int, int, int);

void fill_space(int n, int x, int y) {
    int offset = n / 3;
    x += offset;
    y += offset;
    for (int i = y; i < y + offset; ++i) {
        for (int j = x; j < x + offset; ++j)
            stars[i][j] = ' ';
    }
}

void call_border_realm(int n, int x, int y) {
    int offset = n/3;
    for(int i = 0; i < 3; ++i)
        recursive_print_star(n / 3, x + i * offset, y);
    recursive_print_star(n/3, x, y + offset);
    recursive_print_star(n/3, x + 2 * offset, y + offset);
    for(int i = 0; i < 3; ++i)
        recursive_print_star(n/3, x + i * offset, y + 2 * offset);
}

void recursive_print_star(int n, int x, int y) {
    if (n == 1) {
        return ;
    }
    call_border_realm(n, x, y);
    fill_space(n, x, y);
}

int main() {

    int N;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            stars[j][i] = '*';
    }
    recursive_print_star(N, 0, 0);
    for (int i = 0; i < N; ++i) {
        cout << stars[i] << '\n';
    }
    return 0;
}