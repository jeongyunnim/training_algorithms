//
// Created by 서정윤 on 2025. 4. 5. 오후 3:54
//
#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> S;

    int N;
    cin >> N;
    map<vector<int>, int> M;
    int alpha[26];

    for (int i = 0; i < N; ++i)
    {
        string input;
        int cnt = 0;
        vector<int> V;

        cin >> input;
        bzero(alpha, sizeof alpha);
        for (int j = 0; j < input.size(); ++j)
        {
            int c = input[j] - 'a';
            if (!alpha[c])
            {
                cnt += 1;
                alpha[c] = cnt;
            }
            V.push_back(alpha[c]);
        }
        M[V] += 1;
    }
    int answer = 0;
    for (auto el : M)
    {
        answer += el.second * (el.second - 1) / 2;
    }
    cout << answer;
}