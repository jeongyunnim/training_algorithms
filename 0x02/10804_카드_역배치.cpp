//
// Created by 서정윤 on 8/17/24.
//
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    return ;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cards[20];
    int n = 10, r, l;

    for (int i=0;i<20;i++) cards[i] = i + 1;

    for (int i=0;i<n;i++) {
        cin >> r >> l;
        while (r <= l) {
            swap(cards[r - 1], cards[l - 1]);
            r++;
            l--;
        }
    }
    for (int i=0;i<20;i++) cout << cards[i] << ' ';

    return 0;
}