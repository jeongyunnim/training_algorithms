//
// Created by 서정윤 on 2025. 2. 23. 오후 3:43
//
#include <bits/stdc++.h>

using namespace std;
int building[251][251];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        fill(building[i] + 1, building[i] + N + 1, 0x7fffffff / 2);
        building[i][i] = 0;
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v, flag;
        cin >> u >> v >> flag;
        building[u][v] = 0;
        building[v][u] = !flag;
    }
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (building[i][j] > building[i][k] + building[k][j])
                {
                    building[i][j] = building[i][k] + building[k][j];
                }
            }
        }
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << building[u][v] << '\n';
    }
}