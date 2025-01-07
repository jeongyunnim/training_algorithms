//
// Created by 서정윤 on 2025. 1. 7. 오전 8:58
//
#include <bits/stdc++.h>

using namespace std;
char ip[4][5];
 // 25:09:1985::4846:374:bb
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    vector<string> ans_pre, ans_post;
    cin >> input;
    size_t pre = 0, post, double_col = input.find("::");
    bool is_set = false;
    while (1) {
        if (double_col == string::npos || pre < double_col) {
            post = input.find( ':', pre);
            if (post == string::npos) {
                ans_pre.push_back(input.substr(pre));
                break ;
            }
            ans_pre.push_back(input.substr(pre, post - pre));
        } else {
            if (!is_set) {
                is_set = true;
                pre = double_col + 2;
            }
            post = input.find(':', pre);
            if (post == string::npos) {
                ans_post.push_back(input.substr(pre));
                break ;
            }
            ans_post.push_back(input.substr(pre, post - pre));
        }
        pre = post + 1;
    }

    int section = 0;
    for (int i = 0; i < ans_pre.size(); ++i) {
        for (int j = 0; j < 4 - ans_pre[i].size(); ++j)
            cout << '0';
        cout << ans_pre[i];
        if (section++ < 7)
            cout << ":";
    }
    for (int i = 0; i + ans_pre.size() + ans_post.size() < 8; ++i) {
        cout << "0000";
        if (section++ < 7)
            cout << ":";
    }
    for (int i = 0; i < ans_post.size(); ++i) {
         for (int j = 0; j < 4 - ans_post[i].size(); ++j)
             cout << '0';
         cout << ans_post[i];
        if (section++ < 7)
            cout << ":";
     }
}