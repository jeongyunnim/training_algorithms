//
// Created by 서정윤 on 2024. 12. 2. 오후 4:20
//
#include <bits/stdc++.h>

using namespace std;
int N, remove_target, root;
vector<int> adj[51];

int find_leaf(int cur, int par) {
    int leafs = 0;
    // root의 child의 예외 처리를 명시적으로 처리하지 않았다. 인접한 노드의 개수가 1개 라면 1을 반환하도록 하는 로직을 수정
    int children = 0; // 직관적으로 세어 주는 것이 더 안전하다.
    for (auto child : adj[cur]) {
        if (child == par || child == remove_target) continue ;
        children += 1;
        leafs += find_leaf(child, cur);
    }
    if (!children)
        return 1;
    return leafs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == -1) {
            root = i;
            continue ;
        }
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    cin >> remove_target;
    if (remove_target == root)
        cout << 0;
    else
        cout << find_leaf(root, -1);
}