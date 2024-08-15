//
// Created by 서정윤 on 8/15/24.
//
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void add_one(int arr[], int count) {
    for (int i = 0; i < count; ++i) {
        arr[i] += 1;
    }
}

int main() {
    int nums[10];
    int offset;
    int count = 0;
    string input;

    cin >> input;
    memset(nums, 0, sizeof(nums));
    for (int i = 0; i < input.size(); i++) {
        offset = input[i] - '0';
        if (nums[offset] == 0) {
            if (offset == 6 && nums[offset] == 0 && nums[9] > 0) {
                --nums[9];
                continue;
            }
            if (offset == 9 && nums[offset] == 0 && nums[6] > 0) {
                --nums[6];
                continue;
            }
            add_one(nums, 10);
            ++count;
        }
        --nums[offset];
    }
    cout << count;
    return (0);
}