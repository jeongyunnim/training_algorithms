//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    vector<int> input_nums;
    int pair[1000001];
    int input_count = 0;
    int x = 0;
    int count = 0;

    cin >> input_count;
    for (int i = 0; i < input_count; i++) {
        cin >> x;
        input_nums.push_back(x);
    }
    cin >> x;

    for (int i = 0; i < input_count; i++) {
        pair[input_nums[i]] = 1;
        if (input_nums[i] == x - input_nums[i])
            continue ;
        if (0 < x - input_nums[i] && x - input_nums[i] < 1000001 && pair[x - input_nums[i]]) {
            ++count;
        }
    }
    cout << count;
    return (0);
}