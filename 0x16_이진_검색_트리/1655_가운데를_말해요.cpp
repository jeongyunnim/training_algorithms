//
// Created by 서정윤 on 2025. 1. 2. 오후 9:10
//
#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100001];
priority_queue<int, vector<int>, greater<int> > ri;
priority_queue<int, vector<int>, less<int> > le;

void print_cur() {
    priority_queue<int, vector<int>, less<int> > tmp1 = le;
    priority_queue<int, vector<int>, greater<int> > tmp2 = ri;

    while (!tmp1.empty() || !tmp2.empty()) {
        if (!tmp1.empty()) {
            cout << tmp1.top();
            tmp1.pop();
        }
        cout << '\t';
        if (!tmp2.empty()) {
            cout << tmp2.top();
            tmp2.pop();
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mid;

    int input;
    cin >> N >> input;
    cout << input << '\n';
    le.push(input);
    for (int i = 1; i < N; ++i) {
        cin >> input;
//        cout << "[" << i << "]: " << input << "\n";
        if (le.top() >= input) {
//            cout << le.top() << " >= " << input << " left에 삽입\n";
            le.push(input);
        } else {
//            cout << le.top() << " < " << input << " right에 삽입\n";
            ri.push(input);
        }
        if (ri.size() > le.size()) {
            le.push(ri.top());
            ri.pop();
        } else if (le.size() > ri.size() + 1){
            ri.push(le.top());
            le.pop();
        }
        cout << le.top() << '\n';
//        print_cur();
    }
}