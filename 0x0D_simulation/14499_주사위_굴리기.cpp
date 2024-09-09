//
// Created by 서정윤 on 2024. 9. 9..
//
#include <iostream>

using namespace std;

/** 주사위 도면
  2
4 1 3
  5
  6
 */

enum e_dir {
    EAST = 0,
    WEST,
    NORTH,
    SOUTH,
};

typedef struct s_dice {
    int top;
    int bottom;
    int right;
    int left;
    int front;
    int back;

} t_dice;

t_dice dice;
int M, N, x, y, K;
int map[20][20];
int rolls[1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void roll(int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) return ;
    // 이동
    x = nx;
    y = ny;
    // 주사위 굴리기
    // 오른쪽으로(EAST): top->right, right->bottom, bottom->left, left->top
    int temp1;
    int temp2;
    if (dir == EAST) {
        temp1 = dice.top;
        temp2 = dice.right;
        dice.right = temp1;
        dice.top = dice.left;
        dice.left = dice.bottom;
        dice.bottom = temp2;
    }
    // 왼쪽으로(WEST): top->left, right->top, bottom->right, left->bottom
    else if (dir == WEST) {
        temp1 = dice.top;
        temp2 = dice.left;
        dice.left = temp1;
        dice.top = dice.right;
        dice.right = dice.bottom;
        dice.bottom = temp2;
    }
    // 위로(NORTH): top->back, front->top, bottom->front, back->bottom
    else if (dir == NORTH) {
        temp1 = dice.top;
        temp2 = dice.back;
        dice.back = temp1;
        dice.top = dice.front;
        dice.front = dice.bottom;
        dice.bottom = temp2;
    }
    // 아래로(SOUTH): top->front, front->bottom, bottom->back, back->top
    else {
        temp1 = dice.front;
        temp2 = dice.bottom;
        dice.front = dice.top;
        dice.bottom = temp1;
        dice.top = dice.back;
        dice.back = temp2;
    }

    // 아랫면 0이면 복사
    if (map[x][y] == 0){
        map[x][y] = dice.bottom;
    } else if (map[x][y] != 0){
        dice.bottom = map[x][y];
        map[x][y] = 0;
    }
//    cout << "복사 함" <<'\n';
//    cout << "--------------------\n";
//    cout << " " << dice.back << "  \n";
//    cout << dice.left << dice.top << dice.right << "\n";
//    cout << " " << dice.front << "  \n";
//    cout << " " << dice.bottom << "  \n";
//    cout << "--------------------\n";
    // top 출력
    cout << dice.top << '\n';
}

void roll_dice() {
    for (int i = 0; i < K; ++i) {
        roll(rolls[i] - 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; ++i) {
        cin >> rolls[i];
    }
    roll_dice();
}