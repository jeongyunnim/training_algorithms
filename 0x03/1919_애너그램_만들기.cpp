//
// Created by 서정윤 on 2024. 8. 17..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    char string_input[1001];
    char target_input[1001];
    char *offset;
    int alpha_1[26];
    int alpha_2[26];

    memset(string_input, 0, sizeof(string_input));
    memset(alpha_1, 0, sizeof(alpha_1));
    memset(target_input, 0, sizeof(target_input));
    cin >> string_input;
    cin >> target_input;

    offset = string_input;
    while (*offset != '\0') {
        alpha_1[*offset - 'a'] += 1;
        ++offset;
    }

    memset(alpha_2, 0, sizeof(alpha_2));
    offset = target_input;
    while (*offset != '\0') {
        if (alpha_1[*offset - 'a'] != 0) // alpha 하나만으로 하면 두 번째 문자열의 중복을 처리하기 어렵다.
            alpha_1[*offset - 'a'] -= 1;
        else {
            alpha_2[*offset - 'a'] += 1;
        }
        ++offset;
    }

    for (int i = 0; i < 26; i++) {
        count += alpha_1[i] + alpha_2[i];
    }
    cout << count;
    return 0;
}