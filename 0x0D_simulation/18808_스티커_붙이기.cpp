//
// Created by 서정윤 on 2024. 9. 5..
//
#include <iostream>
#include <cstring>

typedef struct s_sticker {
    int row;
    int col;
    bool shape[10][10];
} t_sticker;

t_sticker stickers[100];
int stickers_len;
int N, M, K, cnt;
bool laptop[41][41];

using namespace std;

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void rotate(t_sticker &src) {
    int temp[10][10];

    for (int i = 0; i < src.row; ++i) {
        for (int j = 0; j < src.col; ++j) {
//            temp[i][j] = src.shape[j][src.row - 1 - i]; 이게 안 되는 이유는 무엇인가?
            temp[j][i] = src.shape[src.row - 1 - i][j];
        }
    }
    my_swap(src.row, src.col);
    for (int i = 0; i < src.row; ++i) {
        for (int j = 0; j < src.col; ++j) {
            src.shape[i][j] = temp[i][j];
        }
    }
}

bool check_size(t_sticker &src) {
    if (src.col < N && src.row < M)
        return true;
    if (src.col < M && src.row < N)
        return true;
    return false;
}

bool is_available(int x, int y, t_sticker &target) {
    for (int i = 0; i < target.row; ++i) {
        for (int j = 0; j < target.col; ++j) {
//            cout << laptop[x + i][y + j] << "|" << target.shape[i][j] << ' ';
            if (x + i >= N || y + j >= M) {
                return false;
            }
            if (laptop[x + i][y + j] == 1 && target.shape[i][j] == 1)
                return false;
        }
    }
    return true;
}

void attach(int x, int y, t_sticker &target) {
    for (int i = 0; i < target.row; ++i) {
        for (int j = 0; j < target.col; ++j) {
            if (target.shape[i][j] == 1)
                laptop[x + i][y + j] = 1;
        }
    }
}

bool is_attached(t_sticker &src) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (is_available(i, j, src)) {
                attach(i, j, src);
                return true;
            }
        }
    }
    return false;
}

void attach_sticker() {
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (is_attached(stickers[i])) { // laptop[i][j]여도 스티커가 비어있으면 가능하다.
                break ;
            }
            else if (j != 3){
                rotate(stickers[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> stickers[stickers_len].row >> stickers[stickers_len].col;
        for (int j = 0; j < stickers[stickers_len].row; ++j) {
            for (int k = 0; k < stickers[stickers_len].col; ++k) {
                cin >> stickers[stickers_len].shape[j][k];
            }
        }
        stickers_len += 1; // 이걸 빼먹다니
    }
    attach_sticker();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (laptop[i][j] == 1)
                cnt += 1;
        }
    }
    cout << cnt;
}
