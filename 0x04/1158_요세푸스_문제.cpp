//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <list>

using namespace std;
int main() {

    int N, K;
    list<int> circle;
    list<int> res;
    list<int>::iterator offset;
    list<int>::iterator temp;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        circle.push_back(i + 1);
    }
    offset = circle.begin();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K - 1; j++) {
            ++offset;
            if (offset == circle.end())
                offset = circle.begin();
        }
        temp = offset;
        res.push_back(*offset);
        offset++;
        if (offset == circle.end())
            offset = circle.begin();
        circle.erase(temp);
    }

    cout << "<";
    for (list<int>::iterator it = res.begin(); it != res.end();) {
        cout << *it;
        if (++it == res.end()) {
            cout << ">\n";
            break ;
        }
        else {
            cout << ", ";
        }
    }
    return 0;
}