//
// Created by 서정윤 on 2024. 8. 17..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int students_boy[6];
    int students_girl[6];
    memset(students_boy, 0, sizeof(students_boy));
    memset(students_girl, 0, sizeof(students_girl));
    bool is_man;
    int line, limit, grade, res = 0;

    cin >> line >> limit;

    while (line--) {
        cin >> is_man >> grade;
        if (is_man)
            students_boy[grade - 1] += 1;
        else
            students_girl[grade - 1] += 1;
    }
    for (int i=0;i<6;i++) {
        if (students_boy[i] != 0) {
            res += students_boy[i] / limit;
            if (students_boy[i] % limit != 0)
                res += 1;
        }
        if (students_girl[i] != 0) {
            res += students_girl[i] / limit;
            if (students_girl[i] % limit != 0)
                res += 1;
        }
    }
    cout << res;
    return 0;
}