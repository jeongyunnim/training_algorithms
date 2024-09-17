//
// Created by 서정윤 on 2024. 9. 16. 오후 7:27
//
#include <iostream>

using namespace std;

//  U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면
enum e_cube {
    UP,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

int N, C;
char input[3];
char cube[7][4][4];
char *cube_side[6][6][6];


void rotate(int side, bool is_plus) {
    char temp[6][6];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (cube_side[side][i][j] != 0)
                temp[i][j] = *(cube_side[side][i][j]);
        }
    }
    if (!is_plus) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (cube_side[side][i][j] != 0)
                    *(cube_side[side][i][j]) = temp[j][4- i];
            }
        }
    } else {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (cube_side[side][i][j] != 0)
                    *(cube_side[side][i][j]) = temp[4- j][i];
            }
        }
    }
}

void spin_cube(char side, bool is_plus) {
    // dir에 따라 90도 혹은 -90도 회전
    // 영향을 받는 인접한 4면 변경
    if (side == 'U') {
        rotate(UP, is_plus);
    } else if (side == 'D') {
        rotate(DOWN, is_plus);
    } else if (side == 'F') {
        rotate(FRONT, is_plus);
    } else if (side == 'B') {
        rotate(BACK,is_plus);
    } else if (side == 'L') {
        rotate(LEFT, is_plus);
    } else {
        rotate(RIGHT, is_plus);
    }
}

void init_pointer() {
    // up
    for (int i = 0; i < 3; ++i) {
        // adj up
        cube_side[UP][0][i + 1] = &(cube[BACK][0][2 - i]);
        // adj down
        cube_side[UP][4][i + 1] = &(cube[FRONT][0][i]);
        // adj left
        cube_side[UP][i + 1][0] = &(cube[LEFT][0][i]);
        // adj right
        cube_side[UP][i + 1][4] = &(cube[RIGHT][0][2 - i]);
    }
    // down
    for (int i = 0; i < 3; ++i) {
        cube_side[DOWN][0][i + 1] = &(cube[FRONT][2][i]);
        cube_side[DOWN][4][i + 1] = &(cube[BACK][2][2 - i]);
        cube_side[DOWN][i + 1][0] = &(cube[LEFT][2][2 - i]);
        cube_side[DOWN][i + 1][4] = &(cube[RIGHT][2][i]);
    }
    // front
    for (int i = 0; i < 3; ++i) {
        cube_side[FRONT][0][i + 1] = &(cube[UP][2][i]);
        cube_side[FRONT][4][i + 1] = &(cube[DOWN][0][i]);
        cube_side[FRONT][i + 1][0] = &(cube[LEFT][i][2]);
        cube_side[FRONT][i + 1][4] = &(cube[RIGHT][i][0]);
    }
    // back
    for (int i = 0; i < 3; ++i) {
        cube_side[BACK][0][i + 1] = &(cube[UP][0][2 - i]);
        cube_side[BACK][4][i + 1] = &(cube[DOWN][2][2 - i]);
        cube_side[BACK][i + 1][0] = &(cube[RIGHT][i][2]);
        cube_side[BACK][i + 1][4] = &(cube[LEFT][i][0]);
    }
    // left
    for (int i = 0; i < 3; ++i) {
        cube_side[LEFT][0][i + 1] = &(cube[UP][i][0]);
        cube_side[LEFT][4][i + 1] = &(cube[DOWN][2 - i][0]);
        cube_side[LEFT][i + 1][0] = &(cube[BACK][i][2]);
        cube_side[LEFT][i + 1][4] = &(cube[FRONT][i][0]);
    }
    // right
    for (int i = 0; i < 3; ++i) {
        cube_side[RIGHT][0][i + 1] = &(cube[UP][2 - i][2]);
        cube_side[RIGHT][4][i + 1] = &(cube[DOWN][i][2]);
        cube_side[RIGHT][i + 1][0] = &(cube[FRONT][i][2]);
        cube_side[RIGHT][i + 1][4] = &(cube[BACK][i][0]);
    }
}

void init() {
    string side_color = "wyrogb";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cube[i][j][k] = side_color[i];
                cube_side[i][j + 1][k + 1] = &(cube[i][j][k]);
            }
        }
    }
}
void print_top() {
    for (int j = 0; j < 3; ++j) {
        cout << cube[UP][j] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    init_pointer();
    for (int i = 0; i < N; ++i) {
        cin >> C;
        init();
        for (int j = 0; j < C; ++j) {
            cin >> input;
            spin_cube(input[0], input[1] == '+');
        }
        print_top();
    }
}