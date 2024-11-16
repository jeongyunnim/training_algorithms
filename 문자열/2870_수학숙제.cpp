#include <bits/stdc++.h>

using namespace std;

bool compare(const string &lhs, const string &rhs) {
    if (lhs.size() != rhs.size())
        return lhs.size() < rhs.size();
    return lhs < rhs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    string input;
    int N;

    cin >> N;
    vector<string> V;
    while (N--) {
        cin >> input;
        string ans;
        bool chain = false;
        for (int i = 0; i <= input.size(); ++i) {
            if (isdigit(input[i])) {
                chain = true;
                if (input[i] == '0' && ans.empty()) continue ;
                ans.push_back(input[i]);
            } else if (chain) {
                chain = false;
                if (ans.empty())
                    V.push_back("0");
                else {
                    V.push_back(ans);
                    ans.clear();
                }
            }
        }
    }
    sort(V.begin(), V.end(), compare);
    for (auto el: V) {
        cout << el << '\n';
    }
}