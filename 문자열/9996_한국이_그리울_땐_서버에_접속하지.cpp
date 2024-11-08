//
// Created by 서정윤 on 2024. 11. 7. 오후 6:53
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt = 0;
    string src, dest;

    cin >> N >> src;
    string st, en;
    size_t pos = src.find('*');
    st = src.substr(0, pos);
    en = src.substr(pos + 1);
    for (int i = 0; i < N; ++i) {
        cin >> dest;
        bool is_match = true;
        for (int j = 0; j < st.size(); ++j) {
            string::iterator it = dest.begin();
            if (it == dest.end() || st[j] != *it) {
                is_match = false;
                break ;
            }
            dest.erase(it);
        }
        for (int j = en.size() - 1, k = dest.size() - 1; is_match && j >= 0; --j) {
            if (k < 0 || en[j] != dest[k]) {
                is_match = false;
                break ;
            }
            k -= 1;
        }
        if (is_match)
            cout << "DA\n";
        else
            cout << "NE\n";
        dest.clear();
    }
}