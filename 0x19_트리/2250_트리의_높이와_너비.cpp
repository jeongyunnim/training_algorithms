//
// Created by 서정윤 on 2024. 12. 9. 오후 3:38
//
#include <bits/stdc++.h>

using namespace std;
int lc[10001];
int rc[10001];
int min_max[10001][2];
int row;
bool is_child[10001];
void pre_trav(int root, int depth) {
    if (lc[root] != -1) {
        pre_trav(lc[root], depth + 1);
    }
    row += 1;
    min_max[depth][0] = min(min_max[depth][0], row);
    min_max[depth][1] = max(min_max[depth][1], row);
    if (rc[root] != -1) {
        pre_trav(rc[root], depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, r, l;
        cin >> x >> l >> r;
        lc[x] = l;
        rc[x] = r;
        if (l != -1)
            is_child[l] = true;
        if (r != -1)
            is_child[r] = true;
    }
    int root;
    for (int i = 1; i <= N; ++i) {
        min_max[i][0] = 0x7fffffff;
        if (!is_child[i])
            root = i;
    }
    pre_trav(root, 1);
    int min_level = 0x7fffffff, max_gap = 0;
    for (int i = 1; i <= N && min_max[i][1]; ++i) {
        int cur_gap;
        if (min_max[i][0] == min_max[i][1])
            cur_gap = 1;
        else
            cur_gap = min_max[i][1] - min_max[i][0] + 1;
        if (max_gap < cur_gap) {
            min_level = i;
            max_gap = cur_gap;
        }
    }
    cout << min_level << ' ' << max_gap;
}