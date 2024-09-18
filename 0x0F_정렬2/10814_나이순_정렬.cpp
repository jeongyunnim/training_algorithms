//
// Created by 서정윤 on 2024. 9. 18. 오전 1:06
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct s_info {
    int age;
    string name;
    int order;
} t_info;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, age;
    string name;
    vector<t_info> V;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> age >> name;
        V.push_back({age, name, i});
    }

    sort(V.begin(), V.end(), [] (t_info &a, t_info &b){
        if (a.age == b.age) {
            return a.order < b.order;
        }
        return a.age < b.age;
    });

    for (auto el : V) {
        cout << el.age << " " << el.name << '\n';
    }
}