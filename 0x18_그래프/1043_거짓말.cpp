//
// Created by 서정윤 on 2024. 11. 12. 오후 4:01
//
#include <bits/stdc++.h>

using namespace std;
int truth_mem;
int parent[51];
long long party[51];

int find_parent(int x) {
    if (parent[x] == x) return x;
    return (parent[x] = find_parent(parent[x]));
}

void merge(int x, int y) {
    int root_x = find_parent(x);
    int root_y = find_parent(y);
    if (root_x < root_y) {
        parent[root_y] = root_x;
    } else {
        parent[root_x] = root_y;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, N_truth, x;
    vector<int> truth_group;
    cin >> N >> M >> N_truth;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < N_truth; ++i) {
        cin >> x;
        truth_group.push_back(x);
        parent[x] = 0;
    }
    for (int i = 1; i <= M; ++i) {
        vector<int> participants;
        int N_participants;

        cin >> N_participants;
        for (int j = 0; j < N_participants; ++j) {
            cin >> x;
            party[i] = x;
            participants.push_back(x);
            if (j > 0)
                merge(participants[j - 1], participants[j]);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= M; ++i) {
        if (find_parent(party[i]) == 0) continue ;
        cnt += 1;
    }
    cout << cnt;
}