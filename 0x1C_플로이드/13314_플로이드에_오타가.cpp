//
// Created by 서정윤 on 2025. 3. 30. 오후 7:45
//
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "100\n";
    for (int i = 0; i < 99; ++i)
    {
        for (int j = 0; j < 99; ++j)
        {
            if (i == j)
                cout << "0 ";
            else
                cout << "100 ";
        }
        cout << "1";
        cout << '\n';
    }
    for (int j = 0; j < 99; ++j)
    {
        cout << "1 ";
    }
    cout << "0\n";
}