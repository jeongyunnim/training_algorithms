//
// Created by 서정윤 on 2024. 9. 8..
//
#include <iostream>

using namespace std;

typedef struct s_wheel
{
    char status[9];
    int top;
    int tilt;
} t_wheel;

t_wheel wheels[4];
int N, input_dir, input_num, score;

void tilt_wheel_left(int num, int dir);
void tilt_wheel_right(int num, int dir);

void tilt_wheel(int num, int dir) {
    char right = wheels[num].status[(wheels[num].top + 2) % 8];
    char left  = wheels[num].status[(wheels[num].top - 2 + 8) % 8];
    char right_pair = 0, left_pair = 0;

            wheels[num].top -= dir;
    if (wheels[num].top < 0)
        wheels[num].top = 7;
    else if (wheels[num].top == 8)
        wheels[num].top = 0;

    // check right
    if (num != 0) {
        left_pair = wheels[num - 1].status[(wheels[num - 1].top + 2) % 8];
        if (left != left_pair)
            tilt_wheel_left(num - 1, dir * -1);
    }

    // check left
    if (num != 3) {
        right_pair = wheels[num + 1].status[(wheels[num + 1].top - 2 + 8) % 8];
        if (right != right_pair)
            tilt_wheel_right(num + 1, dir * -1);
    }
}

void tilt_wheel_right(int num, int dir) {
    if (num >= 4) return ;

    char right = wheels[num].status[(wheels[num].top + 2) % 8];
    char right_pair;

    wheels[num].top -= dir;
    if (wheels[num].top < 0)
        wheels[num].top = 7;
    else if (wheels[num].top == 8)
        wheels[num].top = 0;

    // check right
    if (num != 3) {
        right_pair = wheels[num + 1].status[(wheels[num + 1].top - 2 + 8) % 8];
        if (right != right_pair)
            tilt_wheel_right(num + 1, dir * -1);
    }
}

void tilt_wheel_left(int num, int dir) {
    if (num < 0) return ;

    char left  = wheels[num].status[(wheels[num].top - 2 + 8) % 8];
    char left_pair;

    wheels[num].top -= dir;
    if (wheels[num].top < 0)
        wheels[num].top = 7;
    else if (wheels[num].top == 8)
        wheels[num].top = 0;

    // check left
    if (num != 0) {
        left_pair = wheels[num - 1].status[(wheels[num - 1].top + 2) % 8];
        if (left != left_pair)
            tilt_wheel_left(num - 1, dir * -1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> wheels[i].status[j];
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input_num >> input_dir;
        for (int j = 0; j < 4; ++j) {
            if (j + 1 == input_num)
                wheels[j].tilt = input_num;
            else
                wheels[j].tilt = 0;
        }
        tilt_wheel(input_num - 1, input_dir);
    }
    for (int i = 0; i < 4; ++i) {
        if (wheels[i].status[wheels[i].top] == '1') {
            score += (1 << i);
        }
    }
    cout << score;
}