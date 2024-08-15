//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> input_nums;
    int input_count = 0;
    int x = 0;
    int input;
    int count = 0;

    cin >> input_count;
    for (int i = 0; i < input_count; i++) {
        cin >> input;
        input_nums.push_back(input);
    }
    cin >> x;

    sort(input_nums.begin(), input_nums.end());
    vector<int>::iterator x_offset = find(input_nums.begin(), input_nums.end(), x);
    if (x_offset == input_nums.end())
        cout << 0;
    else {
        while (x_offset != input_nums.end() && *x_offset == x)
        {
            x_offset++;
            ++count;
        }
        cout << count;
    }
    return (0);
}
