//
// Created by 서정윤 on 2024. 11. 17. 오후 4:16
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string animal, sound, goes;
    vector<string> rec;
    vector<string> V;
    int T;

    cin >> T;
    while (T--) {
        while (true) {
            cin >> sound;
            if (sound != "goes")
                rec.push_back(sound);
            else {
                rec.pop_back();
                break ;
            }
        }
        cin >> sound;
        V.push_back(sound);
        while (true) {
            cin >> animal >> goes >> sound;
            if (goes == "goes")
                V.push_back(sound);
            else {
                cin >> goes >> goes;
                break ;
            }
        }
        for (auto el : V) {
            for (auto it = find(rec.begin(), rec.end(), el); it != rec.end();) {
                rec.erase(it);
                it = find(rec.begin(), rec.end(), el);
            }
        }
        for (int i = 0; i < rec.size(); ++i) {
            cout << rec[i];
            if (i == rec.size() - 1) cout << "\n";
            else cout << " ";
        }
        rec.clear();
        V.clear();
    }
}
