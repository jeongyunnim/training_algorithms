//
// Created by 서정윤 on 2024. 8. 19..
//
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

string deque_tostring(deque<int> &D) {
    string answer;
    answer += '[';
    for (size_t i = 0; i < D.size(); i++) {
        answer += to_string(D[i]);
        if (i != D.size() - 1)
            answer += ',';
    }
    answer += "]";
    return answer;
}

bool is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string op, arr;
    deque<int> D;
    int T, n, num = 0;
    bool error_flag = false, reverse_flag = false;
    deque<string> answers;

    cin >> T;
    while (T--) {
        cin >> op >> n >> arr;
        D = deque<int>();
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == '[')
                continue ;
            else if (is_digit(arr[i])) {
                num = num * 10 + arr[i] - '0';
            }
            else if (num != 0){
                D.push_back(num);
                num = 0;
            }
        }

        for (size_t i = 0; i < op.size(); ++i) {
            if (op[i] == 'R') {
                reverse_flag = !reverse_flag;
            } else if (!D.empty()){
                if (reverse_flag)
                    D.pop_back();
                else
                    D.pop_front();
            } else {
                error_flag = true;
                break ;
            }
        }
        if (error_flag)
            answers.push_back("error");
        else {
            if (reverse_flag)
                reverse(D.begin(), D.end());
            answers.push_back(deque_tostring(D));
        }
        error_flag = false;
        reverse_flag = false;
    }
    for (auto s : answers) cout << s << '\n';
    return 0;
}
