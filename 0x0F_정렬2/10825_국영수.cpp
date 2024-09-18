//
// Created by 서정윤 on 2024. 9. 18. 오후 2:40
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct s_info {
    int kor;
    int eng;
    int math;
    char name[11];
} t_info;

t_info input[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i].name >> input[i].kor >> input[i].eng >> input[i].math;
    }
    sort(input, input + N, [](const t_info &lhs, const t_info &rhs) {
        if (lhs.kor != rhs.kor)
            return lhs.kor > rhs.kor;
        else if (lhs.eng != rhs.eng)
            return lhs.eng < rhs.eng;
        else if (lhs.math != rhs.math)
            return lhs.math > rhs.math;
        else
            return strcmp(lhs.name, rhs.name) < 0;
    });
    for (int i = 0; i < N; ++i) {
        cout << input[i].name << '\n';
    }
}