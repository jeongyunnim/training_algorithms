//
// Created by 서정윤 on 2025. 1. 30. 오후 3:31
//
#include <bits/stdc++.h>

using namespace std;

void flush_line(string &line) {
    cout << line << '\n';
    line.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    string line;

    while (1) {
        cin >> word;
        if (cin.eof())
            break ;
        if (word == "<br>") {
            flush_line(line);
            continue ;
        }
        if (word == "<hr>") {
            if (!line.empty())
                flush_line(line);
            cout << setw(81) << setfill('-') << '\n';
            continue ;
        }
        if (!line.empty()) {
            if (line.size() + 1 + word.size() > 80) {
                flush_line(line);
            } else {
                line.push_back(' ');
            }
        }

        line += word;
    }
    flush_line(line);
}