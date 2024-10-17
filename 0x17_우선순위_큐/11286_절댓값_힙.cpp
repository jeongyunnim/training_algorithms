//
// Created by 서정윤 on 2024. 10. 17. 오후 7:36
//
#include <bits/stdc++.h>

using namespace std;
int heap[100005];
int sz = 0; // heap에 들어있는 원소 수

int abs(int x) {
    return x < 0 ? x * -1 : x;
}

void push(int x) {
    heap[++sz] = x;
    int i = sz;
    while (i != 1) {
        int parent = i / 2;
        if (abs(heap[parent]) < abs(heap[i])) break ;
        else if (abs(heap[parent]) == abs(heap[i]) && heap[parent] <= heap[i]) break ;
        swap(heap[parent], heap[i]);
        i = parent;
    }
}

void pop() {
    heap[1] = heap[sz--];
    // 가장 작은 애가 올라오도록 바꿔준다.
    // 왼쪽 자식의 인덱스가 sz 보다 크면 idx는 리프
    int i = 1;
    while (2 * i <= sz) {
        int left = i * 2;
        int right = i * 2 + 1;
        int mn;
        if (right <= sz) {
            if (abs(heap[right]) < abs(heap[left]))
                mn = right;
            else if (abs(heap[right]) > abs(heap[left]))
                mn = left;
            else {
                if (heap[right] < heap[left])
                    mn = right;
                else
                    mn = left;
            }
        } else
            mn = left;
        if (abs(heap[i]) < abs(heap[mn])) break ;
        else if (abs(heap[i]) == abs(heap[mn]) && heap[i] <= heap[mn]) break ;
        swap(heap[mn], heap[i]);
        i = mn;
    }
}

int top() {
    return heap[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (x == 0) {
            if (sz == 0)
                cout << "0\n";
            else {
                cout << top() << '\n';
                pop();
            }
        } else {
            push(x);
        }
    }
}