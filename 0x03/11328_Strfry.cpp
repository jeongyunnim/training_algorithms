//
// Created by 서정윤 on 2024. 8. 17..
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char string_input[1001];
    char target_input[1001];
    char *offset;
    bool flag = true;
    int alpha[26];

    cin >> n;
    while (n--) { // 문자열의 길이도 중요하다.
        memset(string_input, 0, sizeof(string_input));
        memset(alpha, 0, sizeof(alpha));
        memset(target_input, 0, sizeof(target_input));
        cin >> string_input;
        cin >> target_input;

        if (strlen(string_input) != strlen(target_input))
            flag = false;
        offset = string_input;
        while (*offset != '\0' && flag) {
            alpha[*offset - 'a'] += 1;
            ++offset;
        }

        offset = target_input;
        while (*offset != '\0' && flag) {
            if (alpha[*offset - 'a'] <= 0) {
                flag = false;
                break ;
            }
            alpha[*offset - 'a'] -= 1;
            ++offset;
        }

        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
        flag = true;
    }
    return 0;
}