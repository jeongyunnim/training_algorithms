//
// Created by 서정윤 on 2024. 9. 14. 오후 6:27
//
#include <iostream>
#include <cstring>

using namespace std;
int N, mx;
int seq[51][10];
int order[10];
int visited[10];
bool game[4];

int move_base(int n) {
    int score = 0;
//    cout << "[board]\n";
//    cout << " " << game[2] <<  "  \n";
//    cout << game[3] << " " << game[1] << "\n";
//    cout << " " << game[0] <<  "  \n";
    for (int i = 3; i >= 0; --i) {
        if (!game[i]) continue ;
        if (i + n >= 4) {
            score += 1;
            game[i] = false;
        } else {
            game[i + n] = true;
            game[i] = false;
        }
    }
    if (n == 4)
        score += 1;
    else {
        game[n] = true;
    }

//    cout << "[changed]\n";
//    cout << " " << game[2] <<  "  \n";
//    cout << game[3] << " " << game[1] << "\n";
//    cout << " " << game[0] <<  "  \n";
//
//    cout << "score: " << score << '\n';
    return score;
}

void cal_points() {
    int offset = 0;
    int score = 0;
    for (int i = 0; i < N; ++i) {
        // 아웃이 3번 쌓일 때까지 - out 되면 다음 offset부터
        // offset은 다음 이닝에 적용
        memset(game, 0, sizeof(game));
//        cout << '\n' << i << "번째 이닝\n";
        int out = 0;
        while (out < 3) {
            int present = (offset++) % 9;
            if (seq[i][order[present]] == 0) {
                out += 1;
                continue ;
            }
            else if (seq[i][order[present]] == 1) {
                score += move_base(1);
            }
            else if (seq[i][order[present]] == 2) {
                score += move_base(2);
            }
            else if (seq[i][order[present]] == 3) {
                score += move_base(3);
            }
            else {
                score += move_base(4);
            }
        }
//        cout << "\nscore: " << score << "\n";
    }
    mx = max(mx, score);
}

void recursive_comb(int n) {
    // cal every inning
    if (n == 9) {
//        for (int i = 0; i < 9; ++i) {
//            cout << order[i] << ' ';
//        }
//        cout << '\n';
        cal_points();
        return ;
    }
    if (n == 3) {
        recursive_comb(n + 1);
        return ;
    }
    for (int i = 1; i < 9; ++i) {
        if (visited[i]) continue ;
        order[n] = i;
        visited[i] = true;
        recursive_comb(n + 1);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> seq[i][j];
        }
    }
    visited[0] = true;
    order[3] = 0;
    // 0번은 4번 타자로 결정

    recursive_comb(0);

    cout << mx;
}