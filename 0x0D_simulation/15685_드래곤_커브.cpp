//
// Created by 서정윤 on 2024. 9. 14. 오후 3:40
//
#include <iostream>

typedef struct s_dc
{
    int x;
    int y;
    int dir;
    int gen;
} t_dc;

using namespace std;
int N;
t_dc input[21];
int board[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void draw(t_dc tar) {
    int dirs[1024];
    dirs[0] = tar.dir;
    dirs[1] = (tar.dir + 1) % 4;
    for (int i = 2; i < (1 << tar.gen);) {
        // 진행 방향 삽입 0
        for (int j = i - 1; j >= 0 && i < (1 << tar.gen); --j) {
//            cout << "dir[" <<  i << "]: " << dirs[i] << " <= " << (dirs[j] + 1) % 4 << '\n';
            dirs[i] = (dirs[j] + 1) % 4;
            i += 1;
        }
    }
    board[tar.x][tar.y] = 1;
//    cout << "[dirs]: ";
    for (int i = 0; i < (1 << tar.gen); ++i) {
//        cout << dirs[i] << " (" << tar.x << ',' << tar.y <<  ") ";
        tar.x += dx[dirs[i]];
        tar.y += dy[dirs[i]];
        board[tar.x][tar.y] = 1;
    }
//    cout << "\n[board]\n";
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            cout << board[i][j] << " ";
//        }
//        cout << '\n';
//    }
}

int check_surrounded() {
    int res = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                res += 1;
        }
//        cout << '\n';
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i].y >> input[i].x >> input[i].dir >> input[i].gen;
    }
    for (int i = 0; i < N; ++i) {
        draw(input[i]);
    }
    cout << check_surrounded();
}